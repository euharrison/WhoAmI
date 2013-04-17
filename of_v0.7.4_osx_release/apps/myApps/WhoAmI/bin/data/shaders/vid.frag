//#version 120
#extension GL_ARB_texture_rectangle : enable


uniform vec3      iResolution;     // viewport resolution (in pixels)
uniform float     scrwidth;
uniform float     scrheight;
uniform float     iGlobalTime;     // shader playback time (in seconds)
uniform float     iChannelTime[4]; // channel playback time (in seconds)
uniform vec4      iMouse;          // mouse pixel coords. xy: current (if MLB down), zw: click
uniform sampler2DRect iVid;	   // input channel. XX = 2D/Cube
uniform vec4      iDate;           // (year, month, day, time in seconds)

void main() {
	//gl_FragColor = texture2DRect(iVid, vec2(640.0 *  (1.0 - gl_FragCoord.x/iResolution.x), 480.0 * (1.0 - gl_FragCoord.y/iResolution.y))); // gl_FragColor é uma das saídas padrão do GLSL,
	//vec2 pt = vec2(640.0f - (gl_FragCoord.x * 640.0f / iResolution.x), 480.0f - (gl_FragCoord.y * 480.0f / iResolution.y));
	vec2 pt = vec2(640,480);
	pt.x -= gl_FragCoord.x;
	pt.y -= gl_FragCoord.y;
	//pt.x = pt.x * scrwidth;
	//pt.y = pt.y * scrheight;
	vec2 pt2 = pt * iResolution.xy;
	gl_FragColor = texture2DRect(iVid, pt); // gl_FragColor é uma das saídas padrão do GLSL,
	
	//gl_FragColor = texture2DRect(iVid, vec2(640.0, 480.0) * (vec2(1.0, 1.0) - (gl_FragCoord.xy / iResolution.xy))); // gl_FragColor é uma das saídas padrão do GLSL,
							  // armazena o valor diretamente no buffer de cor
	gl_FragDepth = gl_FragCoord.z;
							  // profundidade pode ser alterada pelo shader,
							  // mas não no WebGL/OpenGLES.

}