uniform mat4 projectionMtx, modelViewMtx;

attribute vec3 inPosition;
attribute vec4 inColor;

varying vec4 fragColor;

void main() {
	// gl_Position é uma das saídas padrão de vertex shaders
	gl_Position = projectionMtx * modelViewMtx * vec4(inPosition, 1.0);
	// fragColor é uma das informações que a gente vai passar
	// do vertex shader para o fragment shader
	fragColor = inColor;
}