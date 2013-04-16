uniform vec3      iResolution;     // viewport resolution (in pixels)
uniform float     iGlobalTime;     // shader playback time (in seconds)
uniform float     iChannelTime[4]; // channel playback time (in seconds)
uniform vec4      iMouse;          // mouse pixel coords. xy: current (if MLB down), zw: click
uniform sampler2D iChannel0;
uniform sampler2D iChannel1;
uniform sampler2D iChannel2;
uniform sampler2D iChannel3;	   // input channel. XX = 2D/Cube
uniform vec4      iDate;           // (year, month, day, time in seconds)

//precision mediump float;

void main() {
	gl_FragColor = vec4(gl_FragCoord.xy, 1, 1); // gl_FragColor é uma das saídas padrão do GLSL,
							  // armazena o valor diretamente no buffer de cor
	gl_FragDepth = gl_FragCoord.z;
							  // profundidade pode ser alterada pelo shader,
							  // mas não no WebGL/OpenGLES.
}
