#pragma once

struct MyDisplay {
public:
    MyDisplay() {
        // No need to initialize anything specific for Windows in this case.
    }

    void mouseClickLeft() {
        mouseClick(VK_LBUTTON);
    }

    void mouseClick(int button) {
        INPUT input = { 0 };
        input.type = INPUT_MOUSE;
        input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP; // For left button click
        if (button == VK_RBUTTON) {
            input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP;
        }
        else if (button == VK_MBUTTON) {
            input.mi.dwFlags = MOUSEEVENTF_MIDDLEDOWN | MOUSEEVENTF_MIDDLEUP;
        }
        SendInput(1, &input, sizeof(INPUT));
    }

    void moveMouseRelative(int pitchMovement, int yawMovement) {
        INPUT input = { 0 };
        input.type = INPUT_MOUSE;
        input.mi.dwFlags = MOUSEEVENTF_MOVE;
        input.mi.dx = yawMovement;
        input.mi.dy = pitchMovement;
        SendInput(1, &input, sizeof(INPUT));
    }

    bool isLeftMouseButtonDown() {
        return (GetKeyState(VK_LBUTTON) & 0x8000) != 0;
    }

    bool keyDown(int keyCode) {
        return (GetAsyncKeyState(keyCode) & 0x8000) != 0;
    }

    bool keyDown(std::string keyName) {
        int vkCode = keyNameToVKCode(keyName);
        if (vkCode != 0) {
            return keyDown(vkCode);
        }
        return false;
    }

    std::string trimXKPrefix(const std::string& keyName) {
        if (keyName.compare(0, 3, "XK_") == 0)
            return keyName.substr(3);
        return keyName;
    }

private:
    int keyNameToVKCode(const std::string& keyName) {
        if (keyName.length() != 1) {
            return -1; // Invalid key name for VkKeyScan.
        }
        return VkKeyScan(keyName[0]) & 0xFF;
    }
};
