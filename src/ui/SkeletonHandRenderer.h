//
// Created by David Komorowicz on 2018. 05. 13..
//

#ifndef HANDVR_VIEWER_SKELETONHANDRENDERER_H
#define HANDVR_VIEWER_SKELETONHANDRENDERER_H


#include <QOpenGLFunctions>
#include <src/ui/widgets/HandWidget.h>
#include "HandRenderer.h"

class SkeletonHandRenderer : public HandRenderer, protected QOpenGLFunctions {

public:
    SkeletonHandRenderer(HandWidget &);

    void paint(std::shared_ptr<HandModelBase>) override;

private:
    HandWidget &parent;

    std::unique_ptr<QOpenGLVertexArrayObject> m_vao_axis;
    std::unique_ptr<QOpenGLBuffer> m_vbo_axis;
    std::unique_ptr<QOpenGLBuffer> m_vbo_color;
//    std::unique_ptr<QOpenGLBuffer> m_ibo;
    std::unique_ptr<QOpenGLShaderProgram> axisShader;
//    std::unique_ptr<QOpenGLTexture> m_texture;

    void initialize() override;
};


#endif //HANDVR_VIEWER_SKELETONHANDRENDERER_H
