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
    FILE:         LoadScreen.h
    AUTHOR:       John DiCamillo

*/

#ifndef LoadScreen_h
#define LoadScreen_h

#include "Types.h"
#include "Bitmap.h"
#include "Screen.h"

// +--------------------------------------------------------------------+

class LoadDlg;
class CmpLoadDlg;

class Bitmap;
class DataLoader;
class Font;
class Screen;
class Video;
class VideoFactory;

// +--------------------------------------------------------------------+

class LoadScreen
{
public:
    LoadScreen();
    virtual ~LoadScreen();

    virtual void         Setup(Screen* screen);
    virtual void         TearDown();
    virtual bool         CloseTopmost();

    virtual bool         IsShown()         const { return isShown; }
    virtual void         Show();
    virtual void         Hide();

    virtual void         ShowLoadDlg();
    virtual void         HideLoadDlg();
    virtual LoadDlg*     GetLoadDlg()            { return load_dlg;      }
    virtual CmpLoadDlg*  GetCmpLoadDlg()         { return cmp_load_dlg;  }

    virtual void         ExecFrame();

private:
    Screen*              screen;
    LoadDlg*             load_dlg;
    CmpLoadDlg*          cmp_load_dlg;

    bool                 isShown;
};

// +--------------------------------------------------------------------+

#endif LoadScreen_h

