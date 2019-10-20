#include "GameConfig.h"
#include "Util.h"

using namespace std;
using namespace agbplay;

/*
 * public GameConfig
 */

GameConfig::GameConfig(const string& gameCode)
{
    this->gameCode = gameCode;
    revType = ReverbType::NORMAL;
    resTypeFixed = ResamplerType::LINEAR;
    resType = ResamplerType::LINEAR;
    pcmVol = 0xF;
    engineFreq = 0x4;
    engineRev = 0x0;
    trackLimit = 16;
    revBufSize = 1584;
    mono = false;
}

GameConfig::~GameConfig()
{
}

const string& GameConfig::GetGameCode()
{
    return gameCode;
}

ReverbType GameConfig::GetRevType()
{
    return revType;
}

void GameConfig::SetRevType(ReverbType revType)
{
    this->revType = revType;
}

ResamplerType GameConfig::GetResTypeFixed()
{
    return resTypeFixed;
}

void GameConfig::SetResTypeFixed(ResamplerType resType)
{
    this->resTypeFixed = resType;
}

ResamplerType GameConfig::GetResType()
{
    return resType;
}

void GameConfig::SetResType(ResamplerType resType)
{
    this->resType = resType;
}

uint8_t GameConfig::GetPCMVol()
{
    return pcmVol;
}

void GameConfig::SetPCMVol(uint8_t pcmVol)
{
    this->pcmVol = clip<uint8_t>(0, pcmVol, 0xF);
}

uint8_t GameConfig::GetEngineFreq()
{
    return engineFreq;
}

void GameConfig::SetEngineFreq(uint8_t engineFreq)
{
    this->engineFreq = clip<uint8_t>(1, engineFreq, 12);
}

uint8_t GameConfig::GetEngineRev()
{
    return engineRev;
}

void GameConfig::SetEngineRev(uint8_t engineRev)
{
    this->engineRev = engineRev;
}

uint8_t GameConfig::GetTrackLimit()
{
    return trackLimit;
}

void GameConfig::SetTrackLimit(uint8_t trackLimit)
{
    this->trackLimit = clip<uint8_t>(0, trackLimit, 16);
}

uint16_t GameConfig::GetRevBufSize()
{
    return revBufSize;
}

void GameConfig::SetRevBufSize(uint16_t revBufSize)
{
    this->revBufSize = revBufSize;
}

bool GameConfig::GetMono()
{
    return mono;
}

void GameConfig::SetMono(bool mono)
{
    this->mono = mono;
}

vector<SongEntry>& GameConfig::GetGameEntries()
{
    return gameEntries;
}
