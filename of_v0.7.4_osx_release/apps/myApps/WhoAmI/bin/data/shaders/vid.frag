//#version 120
#extension GL_ARB_texture_rectangle : enable


uniform vec3      iResolution;     // viewport to video resolution ratio
uniform sampler2DRect iVid;	   // video texture

void main() {
	// GLSL 1.2 precisa que cada operador seja aplicado separadamente
	vec2 pt = vec2(640,480) - gl_FragCoord.xy;
	vec2 pt2 = pt * iResolution.xy;
	gl_FragColor = texture2DRect(iVid, pt); // gl_FragColor é uma das saídas padrão do GLSL,
	gl_FragDepth = gl_FragCoord.z;
							  // profundidade pode ser alterada pelo shader,
							  // mas não no WebGL/OpenGLES.

}