#version 120
#extension GL_ARB_texture_rectangle : enable

uniform sampler2DRect tex0;
uniform sampler2DRect conidiaTex;

void main (void){
  vec2 pos = gl_TexCoord[0].st;

  vec4 hyphae = texture2DRect(tex0, pos);
  vec3 conidia = texture2DRect(conidiaTex, pos).rgb;

  vec4 outColor;
  // If the sum of the parts > 0 it means it's not black so there's something there.
  // Because conidia's alpha is always 1, we'll add the color parts and divide by 3 to determine it.
  float conidiaLight = conidia.r+conidia.g+conidia.b;
  if (conidiaLight > 0) {
    float alpha = conidiaLight/3.0; 
    outColor.rgb = hyphae.rgb * (1-alpha) + conidia.rgb;
    outColor.a = 1;
  } else {
    outColor = hyphae;
  }

  gl_FragColor = vec4(outColor);
}
