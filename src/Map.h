#pragma once

#include "levels/Final.h"
#include "levels/Lab.h"
#include "levels/Other.h"
#include "levels/SpaceStation.h"
#include "levels/Tower.h"
#include "levels/Warp.h"
#include "Entity.h"
#include "Graphics.h"
#include <vector>
#include "Music.h"
#include "Editor.h"

extern EditorClass ed;

class MapClass
{
public:
    MapClass();

    int RGB(int red,int green,int blue);

    int intpol(int a, int b, float c);

    void setteleporter(int t, int x, int y);

    void settrinket(int t, int x, int y);

    void resetmap();

    void resetnames();

    void transformname(int t);

    std::string getglitchname(int x, int y);

    void initmapdata();

    int finalat(int x, int y);

    int maptiletoenemycol(int t);

    void changefinalcol(int t, EntityClass& obj, Game& game);

    void setcol(const int r1, const int g1, const int b1 , const int r2, const  int g2, const int b2, const int c);

    void updatetowerglow();

    void nexttowercolour();

    void settowercolour(int t);

    bool spikecollide(int x, int y);

    bool collide(int x, int y);

    void fillareamap(std::vector<std::string>& tmap);

    void settile(int xp, int yp, int t);

    void fillcontent(std::vector<std::string>& tmap);


    int area(int _rx, int _ry);

    void exploretower();

    void hideship();

    void showship();

    void resetplayer(Graphics& dwgfx, Game& game, EntityClass& obj, MusicClass& music);

    void warpto(int rx, int ry , int t, int tx, int ty,  Graphics& dwgfx, Game& game, EntityClass& obj, MusicClass& music);

    void gotoroom(int rx, int ry, Graphics& dwgfx,  Game& game, EntityClass& obj, MusicClass& music);

    std::string currentarea(int t);

    void loadlevel(int rx, int ry, Graphics& dwgfx, Game& game, EntityClass& obj, MusicClass& music);


    std::vector <int> roomdeaths;
    std::vector <int> roomdeathsfinal;
    std::vector <int> areamap;
    std::vector <int> contents;
    std::vector <int> explored;
    std::vector <int> vmult;
    std::vector <std::string> tmap;

    int temp;
    int temp2;
    int j;
    int background;
    int rcol;
    int tileset;
    bool warpx;
    bool warpy;

    std::string roomname;

    //Special tower stuff
    bool towermode;
    float ypos;
    int bypos;
    int cameramode;
    int cameraseek, cameraseekframe;
    int resumedelay;
    bool minitowermode;
    int scrolldir;

    //This is the old colour cycle
    int r, g,b;
    int check, cmode;
    int towercol;
    int colstate, colstatedelay;
    int colsuperstate;
    int spikeleveltop, spikelevelbottom;
    bool tdrawback;
    int bscroll;
    //final level navigation
    int finalx;
    int finaly;
    bool finalmode;
    bool finalstretch;

    //Variables for playing custom levels
    bool custommode;
    bool custommodeforreal;
    int customx, customy;
    int customwidth, customheight;
    int customtrinkets;
    int customcrewmates;
    int custommmxoff, custommmyoff, custommmxsize, custommmysize;
    int customzoom;
    bool customshowmm;

    std::vector<std::string> specialnames;
    int glitchmode;
    int glitchdelay;
    std::string glitchname;

    //final level colour cycling stuff
    bool final_colormode;
    int final_mapcol;
    int final_aniframe;
    int final_aniframedelay;
    int final_colorframe, final_colorframedelay;

    //Teleporters and Trinkets on the map
    std::vector<point> teleporters;
    std::vector<point> shinytrinkets;

    int numteleporters, numshinytrinkets;
    bool showteleporters, showtargets, showtrinkets;

    //Roomtext
    int roomtextx[100], roomtexty[100];
    bool roomtexton;
    std::vector<std::string> roomtext;
    int roomtextnumlines;

    //Levels
    levels::Final finallevel;
    levels::Lab lablevel;
    levels::Other otherlevel;
    levels::SpaceStation spacestation2;
    levels::Tower tower;
    levels::Warp warplevel;
    int extrarow;

    //Accessibility options
    bool invincibility;

    //Map cursor
    int cursorstate, cursordelay;
};
