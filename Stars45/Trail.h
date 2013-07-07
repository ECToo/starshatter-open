/*  Starshatter OpenSource Distribution
    Copyright (c) 1997-2004, Destroyer Studios LLC.
    All Rights Reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.
    * Neither the name "Destroyer Studios" nor the names of its contributors
      may be used to endorse or promote products derived from this software
      without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.

    SUBSYSTEM:    Stars.exe
    FILE:         Trail.h
    AUTHOR:       John DiCamillo


    OVERVIEW
    ========
    Missile Trail (Graphic) class
*/

#ifndef Trail_h
#define Trail_h

#include "Types.h"
#include "Geometry.h"
#include "Polygon.h"
#include "SimObject.h"
#include "Graphic.h"

// +--------------------------------------------------------------------+

class Trail : public Graphic
{
public:
    Trail(Bitmap* tex, int n=512);
    virtual ~Trail();

    virtual void      UpdateVerts(const Point& cam_pos);
    virtual void      Render(Video* video, DWORD flags);
    virtual void      AddPoint(const Point& v);
    virtual double    AverageLength();

    virtual void      SetWidth(double w)   { width = w; }
    virtual void      SetDim(int d)        { dim   = d; }

protected:
    int            ntrail;
    int            maxtrail;
    Point*         trail;

    double         length;
    double         width;
    int            dim;

    int            npolys, nverts;
    Poly*          polys;
    VertexSet*     verts;
    Bitmap*        texture;
    Material       mtl;

    double         length0, length1;
    double         last_point_time;
};

#endif Trail_h

