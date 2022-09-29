#ifndef FINN_RUNNER_GAMEMAP_H
#define FINN_RUNNER_GAMEMAP_H


class GameMap {
    public:
        void createSpawnArea();
        void createTerrain();
        void objectPlacement();
        void spawnGameCharacter();
    private:
        float spawnX;
        float spawnY;
};


#endif //FINN_RUNNER_GAMEMAP_H
