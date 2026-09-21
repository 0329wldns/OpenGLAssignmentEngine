#pragma once
#include "pch.h"
#include "Struct.h"
#include "Singleton.h"

enum class KEY
{
    UP, DOWN, LEFT, RIGHT,
    W, A, S, D,
    MOUSE_L, MOUSE_R,
    C, M, Y, G, K, T,
    NUM_1, NUM_2, NUM_3, NUM_4,
    ESC,
    LAST
};

enum class KEY_STATE
{
    NONE,
    TAP,
    HOLD,
    AWAY
};

struct KeyInfo
{
    KEY_STATE keyState{};
    bool prevPush{};
};

class KeyManager : public Singleton<KeyManager>
{
    friend class Singleton<KeyManager>;

public:
    void init();
    void update();

    KEY_STATE getKeyState(KEY _key) const { return keyInfo[(int)_key].keyState; }
    Vector2 getMousePos() const { return curMousePos; }

private:
    KeyManager() = default;

private:
    vector<KeyInfo> keyInfo;
    Vector2 curMousePos{};
};