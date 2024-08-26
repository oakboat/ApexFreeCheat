#pragma once
struct LocalPlayer {
    MyDisplay *display;
    uint64_t base;
    bool dead;
    bool knocked;
    bool inAttack;
    bool inZoom;
    bool inJump;
    bool grippingGrenade;
    Vector3D localOrigin;
    Vector3D CameraPosition;
    Vector2D viewAngles;
    Vector2D punchAngles;
    Vector2D punchAnglesPrev;
    Vector2D punchAnglesDiff;
    uint64_t actWeaponID;
    uint64_t currentWeapon;
    uint64_t actWeaponIDMasked;
    uint64_t highlightSettingsPtr;
    uint64_t weaponEntity;
    uint64_t weaponHandle;
    uint64_t weaponHandleMasked;
    int weaponIndex;
    int frameCount; 
    int grenadeID;
    int ammoInClip;
    int teamNumber;
    int squadNumber;
    int currentHealth;
    float WeaponProjectileSpeed;
    float WeaponProjectileScale;
    float worldtime;
    float traversalStartTime;
    float traversalProgress;
    float traversalReleaseTime;
    float onWall;

    void reset() {
        base = 0;
    }

    void readFromMemory(Level* map) {
        if (mem::process_id != 0) {
            base = read<uint64_t>(OFF_REGION + OFF_LOCAL_PLAYER, "LocalPlayer base");
            if (base == 0) return;
            dead = read<short>(base + OFF_LIFE_STATE, "LocalPlayer base") > 0;
            knocked = read<short>(base + OFF_BLEEDOUT_STATE, "LocalPlayer base") > 0;
            inZoom = read<short>(base + OFF_ZOOMING, "LocalPlayer inZoom") > 0;
            teamNumber = read<int>(base + OFF_TEAM_NUMBER, "LocalPlayer teamNumber");

            squadNumber = read<int>(base + OFF_SQUAD_ID, "LocalPlayer squadNumber");
            inAttack = read<bool>(OFF_REGION + OFF_IN_ATTACK, "LocalPlayer inAttack") > 0;
            inJump = read<bool>(OFF_REGION + OFF_IN_JUMP, "LocalPlayer inJump") > 0;
            highlightSettingsPtr = read<uint64_t>( OFF_REGION + OFF_GLOW_HIGHLIGHTS, "LocalPlayer HiglightsSettingPtr");
            localOrigin = read<Vector3D>(base + OFF_LOCAL_ORIGIN, "LocalPlayer localOrigin");
            
            frameCount = read<int>(OFF_REGION + OFF_GLOBAL_VARS + sizeof(double), "LocalPlayer frameCount");
            worldtime = read<float>(base + OFFSET_TIME_BASE, "LocalPlayer worldTime");
            traversalStartTime = read<float>(base + OFFSET_TRAVERSAL_START_TIME, "LocalPlayer traversalStartTime");
            traversalProgress = read<float>(base + OFFSET_TRAVERSAL_PROGRESS, "LocalPlayer traversalProgress"); 
            traversalReleaseTime = read<float>(base + OFFSET_TRAVERSAL_RELEASE_TIME, "LocalPlayer traversalReleaseTime"); 
            onWall = read<float>(base + OFFSET_WALL_RUN_START_TIME, "LocalPlayer wallRunStartTime");

            currentHealth = read<int>(base + OFF_CURRENT_HEALTH, "LocalPlayer currentHealth");
            CameraPosition = read<Vector3D>(base + OFF_CAMERAORIGIN, "LocalPlayer CameraPosition");
            viewAngles = read<Vector2D>(base + OFF_VIEW_ANGLES, "LocalPlayer viewAngles");
            punchAngles = read<Vector2D>(base + OFF_PUNCH_ANGLES, "LocalPlayer punchAngles");
            punchAnglesDiff = punchAnglesPrev.Subtract(punchAngles);
            punchAnglesPrev = punchAngles;
            if (!dead && !knocked && map->playable) {
                weaponHandle = read<uint64_t>(base + OFF_WEAPON_HANDLE, "LocalPlayer weaponHandle");
                weaponHandleMasked = weaponHandle & 0xffff;
            
                weaponEntity = read<uint64_t>(OFF_REGION + OFF_ENTITY_LIST + (weaponHandleMasked << 5), "LocalPlayer weaponEntity");
                grenadeID = read<int>(base + OFF_GRENADE_HANDLE, "LocalPlayer grenadeID");
                grippingGrenade = grenadeID == -251 ? true : false;
                ammoInClip = read<int>(weaponEntity + OFFSET_AMMO, "LocalPlayer ammoInClip"); 
                weaponIndex = read<int>(weaponEntity + OFF_WEAPON_INDEX, "LocalPlayer weaponIndex");
                actWeaponID = read<uint64_t>((base + OFF_VIEW_MODELS), "LocalPlayer active Weapon ID");
                actWeaponIDMasked = actWeaponID & 0xFFFF;
                currentWeapon = read<uint64_t>(OFF_REGION + OFF_ENTITY_LIST + (actWeaponIDMasked << 5), "LocalPlayer current Weapon");
                WeaponProjectileSpeed = read<float>(weaponEntity + OFF_PROJECTILESPEED, "LocalPlayer WeaponProjectileSpeed");
                WeaponProjectileScale = read<float>(weaponEntity + OFF_PROJECTILESCALE, "LocalPlayer WeaponProjectileScale");   
            }
        }else{
            std::cout << "OPEN APEX LEGENDS!\n";
            return;
        }
        
    }
    bool isValid(){
        return base != 0;
    }
    bool isCombatReady(){
        if (base == 0) return false;
        if (dead) return false;
        if (knocked) return false;
        return true;
    }
    void setYaw(float angle){
        uint64_t ptruint64_t = base + OFF_VIEW_ANGLES + sizeof(float);
        write<float>(ptruint64_t, angle);
    }
    float getPunchPitch(){
        uint64_t ptruint64_t = base + OFF_PUNCH_ANGLES;
        float result = read<float>(ptruint64_t,"PunchPitch");
        return result;
    }
    float getPunchYaw(){
        uint64_t ptruint64_t = base + OFF_PUNCH_ANGLES + sizeof(float);
        float result = read<float>(ptruint64_t, "PunchYaw");
        return result;
    }
    float getPitch(){
        uint64_t ptruint64_t = base + OFF_VIEW_ANGLES;
        float result = read<float>(ptruint64_t, "getPitch");
        return result;
    }
    void setPitch(float angle){
        uint64_t ptruint64_t = base + OFF_VIEW_ANGLES;
        write<float>(ptruint64_t, angle);
    }
    float getYaw() {
        uint64_t ptruint64_t = base + OFF_VIEW_ANGLES + sizeof(float);
        float result = read<float>(ptruint64_t,"getYaw");
        return result;
    }
};
