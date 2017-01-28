//
//  Shader.fsh
//  wordfangle
//
//  Created by JC on 28/01/2017.
//  Copyright © 2017 Amju. All rights reserved.
//

varying lowp vec4 colorVarying;

void main()
{
    gl_FragColor = colorVarying;
}
