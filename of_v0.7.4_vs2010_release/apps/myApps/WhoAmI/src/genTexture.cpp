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
    //camera.enableOrtho();
    camera.setAspectRatio(1);
    camera.setPosition(0, 0, -1);
    camera.setFov(45.0);
    camera.lookAt(ofVec3f(0,0,0));
}


void GenTexture::applySequence() {
    // faz setup do FBO para renderização e chama um por um dos "shaders"
    fbo.begin();
    camera.begin();
    //ofClear(0, 0, 0);
    for (ShaderSeq::const_iterator i = sequence.begin();
         i!=sequence.end(); i++) {
        (*i)->apply();
    }
    camera.end();
    fbo.end();
}

void GenTexture::addShader(GenTextureShader *shader) {
    sequence.push_back(shader);
}

GenTexture::~GenTexture() {}

ofTexture& GenTexture::getTexture() {
    return fbo.getTextureReference();
}

GenTextureFragShader::GenTextureFragShader(const std::string &fn): filename(fn) {
}

void GenTextureFragShader::setup() {
    ofMesh mesh;
    mesh.addTexCoord(ofVec2f(0, 0));
    mesh.addVertex(ofVec3f(-1, -1, 0));
    mesh.addTexCoord(ofVec2f(512, 0));
    mesh.addVertex(ofVec3f(1, -1, 0));
    mesh.addTexCoord(ofVec2f(0, 512));
    mesh.addVertex(ofVec3f(-1, 1, 0));
    mesh.addTexCoord(ofVec2f(512, 512));
    mesh.addVertex(ofVec3f(1, 1, 0));
    vbo.setMesh(mesh, GL_STATIC_DRAW);
    if(!shader.load(ofToDataPath("shaders/simple.vert"), ofToDataPath("shaders/"+filename))) {
        ofLog(OF_LOG_ERROR, "error loading shader %s", filename.c_str());
    }
    if(!shader.linkProgram()) {
        ofLog(OF_LOG_ERROR, "error linking shader with %s", filename.c_str());
    };
    // shader uniforms from ShaderToy
    //shader.setUniform3f("iResolution", 512, 512, 0);
}
void GenTextureFragShader::apply() {
    shader.setUniform3f("iResolution", 512, 512, 0);
    shader.setUniform1f("iGlobalTime", ofGetElapsedTimef());
    shader.setUniform4f("iMouse", 256, 256, 0, 0);
    shader.setUniform4f("iChannelTime", 0, 0, 0, 0);
    shader.setUniform4f("iDate", 0, 0, 0, 0);
    shader.begin();
    vbo.draw(GL_TRIANGLE_STRIP, 0, 4);
    shader.end();
}

GenTextureImageShader::GenTextureImageShader(ofImage &image):img(image) {
    
}

void GenTextureImageShader::apply() {
    ofTexture &tex = img.getTextureReference();
    tex.bind();
    ofRect(-1, -1, 1, 1);
    tex.unbind();
}
