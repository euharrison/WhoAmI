//attribute vec3 inPosition;
//attribute vec4 inColor;

varying vec2 v_texCoord2D;
varying vec3 v_texCoord3D;
varying vec4 v_color;
void main() {
	// gl_Position é uma das saídas padrão de vertex shaders
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
	// fragColor é uma das informações que a gente vai passar
	// do vertex shader para o fragment shader
	v_color = gl_Color;
	//v_texCoord3D = gl_MultiTexCoord0.xyz;
	//v_texCoord2D = gl_MultiTexCoord0.xy;
	v_texCoord3D = vec3(gl_Position.xy, 0);
	v_texCoord2D = gl_Position.xy;
}