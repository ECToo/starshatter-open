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
    FILE:         CampaignPlanMission.h
    AUTHOR:       John DiCamillo


    OVERVIEW
    ========
    CampaignPlanMission generates missions and mission
    info for the player's combat group as part of a
    dynamic campaign.
*/

#ifndef CampaignPlanMission_h
#define CampaignPlanMission_h

#include "Types.h"
#include "CampaignPlan.h"

// +--------------------------------------------------------------------+

class CampaignMissionRequest;
class CombatGroup;
class CombatUnit;
class CombatZone;

// +--------------------------------------------------------------------+

class CampaignPlanMission : public CampaignPlan
{
public:
    static const char* TYPENAME() { return "CampaignPlanMission"; }

    CampaignPlanMission(Campaign* c) : CampaignPlan(c), start(0), slot(0) { }
    virtual ~CampaignPlanMission() { }

    // operations:
    virtual void   ExecFrame();

protected:
    virtual void                     SelectStartTime();
    virtual CampaignMissionRequest*  PlanCampaignMission();
    virtual CampaignMissionRequest*  PlanStrategicMission();
    virtual CampaignMissionRequest*  PlanRandomStarshipMission();
    virtual CampaignMissionRequest*  PlanRandomFighterMission();
    virtual CampaignMissionRequest*  PlanStarshipMission();
    virtual CampaignMissionRequest*  PlanFighterMission();

    CombatGroup*   player_group;
    int            start;
    int            slot;
};

#endif CampaignPlanMission_h

