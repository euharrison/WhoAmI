//
//  tertura.h
//  opengl2
//
//  Created by Tiago Rezende on 4/2/13.
//
//

#ifndef __opengl2__tertura__
#define __opengl2__tertura__

#include "ofMain.h"
#include <vector>
#include <string>

class GenTextureShader {
protected:
    ofVbo vbo;
public:
    virtual void setup() {};
    virtual ~GenTextureShader() {}
    virtual void apply() = 0;
};

class GenTexture {
    ofFbo fbo;
    ofCamera camera;
    typedef std::vector<GenTextureShader*> ShaderSeq;
    ShaderSeq sequence;
public:
    GenTexture();
    ~GenTexture();
    void applySequence();
    ofTexture& getTexture();
    void addShader(GenTextureShader * shader);
};


class GenTextureFragShader: public GenTextureShader {
    ofShader shader;
    std::string filename;
public:
    GenTextureFragShader(const std::string &filename);
    virtual void setup();
    virtual void apply();
};


class GenTextureImageShader: public GenTextureShader {
    ofImage &img;
public:
    explicit GenTextureImageShader(ofImage &image);
    virtual void apply();
};



#endif /* defined(__opengl2__tertura__) */