//
//  tertura.cpp
//  opengl2
//
//  Created by Tiago Rezende on 4/2/13.
//
//

#include "genTexture.h"
#include <fstream>

GenTexture::GenTexture() {
    fbo.allocate(512, 512, GL_RGBA);
}


void GenTexture::applySequence() {
    // faz setup do FBO para renderização e chama um por um dos "shaders"
    fbo.begin();
    for (ShaderSeq::const_iterator i = sequence.begin();
         i!=sequence.end(); i++) {
        (*i)->apply();
    }
    fbo.end();
}

GenTexture::GenTexture() {}

ofTexture& GenTexture::getTexture() {
    return fbo.getTextureReference();
}

GenTextureFragShader::GenTextureFragShader(const std::string &fn): filename(fn) {
    
}

void GenTextureFragShader::setup() {
    if(!shader.load(ofDataPath("shaders/simple.vert"), ofDataPath("shaders/"+filename))) {
        std::cerr << "error loading shader " << filename << std::endl;
    }
    if(!shader.linkProgram()) {
        std::cerr << "error linking shader with " << filename << std::endl;
    };
}
void GenTextureFragShader::apply() {
    shader.begin();
    ofRect(0, 0, 1, 1);
    shader.end();
}
