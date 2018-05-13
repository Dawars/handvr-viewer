//
// Created by David Komorowicz on 2018. 05. 13..
//

#include <src/sensor/leapmotion/HandModel.h>
#include "SkeletonHandRenderer.h"

struct Vertex {
    QVector3D position;
    QVector3D color;
};

Vertex axis[] = {
        {QVector3D(0, 0, 0),  QVector3D(1, 0, 0)},
        {QVector3D(10, 0, 0), QVector3D(1, 0, 0)},
        {QVector3D(0, 0, 0),  QVector3D(0, 1, 0)},
        {QVector3D(0, 10, 0), QVector3D(0, 1, 0)},
        {QVector3D(0, 0, 0),  QVector3D(0, 0, 1)},
        {QVector3D(0, 0, 10), QVector3D(0, 0, 1)},
};

SkeletonHandRenderer::SkeletonHandRenderer(HandWidget &widget) :
        parent{widget} {
}

void SkeletonHandRenderer::initialize() {
    initializeOpenGLFunctions();

    m_vao_axis = std::make_unique<QOpenGLVertexArrayObject>();
    m_vbo_axis = std::make_unique<QOpenGLBuffer>(QOpenGLBuffer::VertexBuffer);
//    m_ibo = std::make_unique<QOpenGLBuffer>(QOpenGLBuffer::IndexBuffer);

    axisShader = std::make_unique<QOpenGLShaderProgram>();
    axisShader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/Axis.vert");
    axisShader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/Axis.frag");
    axisShader->link();

    m_vao_axis->create();
    if (m_vao_axis->isCreated())
        m_vao_axis->bind();

    if (m_vbo_axis->create()) {
        m_vbo_axis->bind();
        m_vbo_axis->allocate(axis, 6 * sizeof(Vertex));
        m_vbo_axis->setUsagePattern(QOpenGLBuffer::UsagePattern::StaticDraw);


        axisShader->setAttributeBuffer("position", GL_FLOAT, offsetof(Vertex, position), 3, sizeof(Vertex));
        axisShader->enableAttributeArray(0);
        axisShader->setAttributeBuffer("color", GL_FLOAT, offsetof(Vertex, color), 3, sizeof(Vertex));
        axisShader->enableAttributeArray(1);


        m_vbo_axis.release();
        m_vbo_color.release();
    }
}

void SkeletonHandRenderer::paint(std::shared_ptr<HandModelBase> handModel) {

    axisShader->bind();
    axisShader->setUniformValue("transform", parent.getVP());


    const auto &hand = handModel->GetLeapHand();

    for (auto &finger: hand->fingers()) {
        for (int i = 0; i <= Leap::Bone::Type::TYPE_DISTAL; ++i) {

            const Leap::Bone &bone = finger.bone(static_cast<Leap::Bone::Type>(i));

            const Leap::Vector &pos = bone.prevJoint();

            QMatrix4x4 handMat = parent.getVP();
            handMat.translate(pos.x, pos.y, pos.z);
            axisShader->setUniformValue("transform", handMat);

            m_vao_axis->bind();
            glDrawArrays(GL_LINES, 0, 6);

        }
    }
    const Leap::Vector &handPos = hand->palmPosition();

    QMatrix4x4 handMat = parent.getVP();
    handMat.translate(handPos.x, handPos.y, handPos.z);

    // rendering hand center
    axisShader->setUniformValue("transform", handMat);

    m_vao_axis->bind();
    glDrawArrays(GL_LINES, 0, 6);

}