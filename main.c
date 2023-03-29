#include <stdio.h>
#include <libsx.h>
#include <stdlib.h>
#include"w.h"
#define DEFAULT -1

extern unsigned char calcBit(unsigned int num);
extern char * myItoa(int num);
extern void myStrcpy(char * target, char * src, char end);
extern int myStrlen(char * src, char end);
extern char ** split(char * src, char s);
extern char * combineTwoString(char * s1, int sub1, char * s2, int sub2);
extern char * combineBigChars(char * b1, char * b2);



// translate a common char to a bigger one;
char * atobig(char src){
    switch (src) {
        case '0':
            return " +-+ \n | | \n | | \n | | \n +-+ ";
        case '1':
            return "  ^  \n /|  \n  |  \n  |  \n -+- ";
        case '2':
            return " --+ \n   | \n +-+ \n |   \n +-- ";
        case '3':
            return " --+ \n   | \n --+ \n   | \n --+ ";
        case '4':
            return " ||  \n ||  \n ++- \n  |  \n  |  ";
        case '5':
           
            return " +-- \n |   \n +-+ \n   | \n --+ ";
        case '6':
            return " +-- \n |   \n +-+ \n | | \n +-+ ";
        case '7':
            return " --+ \n   | \n   | \n   | \n   | ";
        case '8':
            return " +-+ \n | | \n +-+ \n | | \n +-+ ";
        case '9':
            return " +-+ \n | | \n +-+ \n   | \n --+ ";
        case 'a':
            return "     \n ++  \n ++- \n     \n     ";
        case 'd':
            return "  |  \n ++  \n ++  \n     \n     ";
        case 'e':
            return "     \n ++  \n +-  \n     \n     ";
        case 'f':
            return "  +- \n -+- \n  |  \n  |  \n     ";
        case 'i':
            return "  .  \n  |  \n  |  \n     \n     ";
        case 'l':
            return " |   \n |   \n +-  \n     \n     ";
        case 'n':
            return "     \n ++  \n ||  \n     \n     ";
        case 'm':
            return "     \n +++ \n ||| \n     \n     ";
        case 'o':
            return "     \n ++  \n ++  \n     \n     ";
        case 's':
            return "     \n \\-  \n -\\  \n     \n     ";
        case 't':
            return "  |  \n -+- \n  +- \n     \n     ";
        case 'u':
            return "     \n ||  \n ++- \n     \n     ";
        case 'D':
            return " +-. \n | ) \n +-` \n     \n     ";
        case 'E':
            return " +-- \n +-- \n +-- \n     \n     ";
        case 'F':
            return " +-- \n +-  \n |   \n     \n     ";
        case 'I':
            return " -+- \n  |  \n -+- \n     \n     ";
        case 'L':
            return " |   \n |   \n +-- \n     \n     ";
        case 'M':
            return " +++ \n ||| \n ||| \n     \n     ";
        case 'R':
            return " ++  \n ++  \n |\\ \n     \n     ";
        case '\'':
            return "  /  \n o   \n     \n     \n     ";
        case '!':
            return "  |  \n  |  \n  .  \n     \n     ";
        default:
            return "+++++\n+++++\n+++++\n+++++\n+++++";
    }
}
char * atoMoreBig(char src){
    switch (src) {
        case '0':
            return "      |================|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |================|      ";
        case '1':
            return "             /=|              \n            / =|              \n           / |=|              \n          /  |=|              \n         /   |=|              \n             |=|              \n             |=|              \n             |=|              \n             |=|              \n             |=|              \n             |=|              \n             |=|              \n             |=|              \n             |=|              \n         |=========|          ";
        case '2':
            return "      |================|      \n                     |=|      \n                     |=|      \n                     |=|      \n                 /=====|      \n                //            \n               //             \n              //              \n             //               \n            //                \n           //                 \n      |====/         |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |================|      ";
        case '3':
            return "      |================|      \n                     |=|      \n                     |=|      \n                     |=|      \n                     |=|      \n                     |=|      \n                     |=|      \n      |================|      \n                     |=|      \n                     |=|      \n                     |=|      \n                     |=|      \n                     |=|      \n                     |=|      \n      |================|      ";
        case '4':
            return "             /=|              \n            /|=|              \n           / |=|              \n          /  |=|              \n         /   |=|              \n        /    |=|              \n       /     |=|              \n      /      |=|              \n     /       |=|              \n    /========|=|=======       \n             |=|              \n             |=|              \n             |=|              \n             |=|              \n             |=|              ";
        case '5':
            return "      |================|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |=====\\                 \n            \\\\                \n             \\\\               \n              \\\\              \n               \\\\             \n                \\\\            \n                 \\\\           \n                  \\====|      \n      |=|            |=|      \n      |=|            |=|      \n      |================|      ";
        case '6':
            return "      |================|      \n      |=|                     \n      |=|                     \n      |=|                     \n      |=|                     \n      |=|                     \n      |=|                     \n      |================|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |================|      ";
        case '7':
            return "      |================|      \n                     |=|      \n                     |=|      \n                    //=|      \n                   //         \n                  //          \n                 //           \n                //            \n               //             \n              //              \n             //               \n            //                \n           //                 \n          //                  \n         //                   ";
        case '8':
            return "      |================|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |================|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |================|      ";
        case '9':
            return "      |================|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |=|            |=|      \n      |================|      \n                     |=|      \n                     |=|      \n                     |=|      \n                     |=|      \n                     |=|      \n                     |=|      \n      |================|      ";
    }
}
char * atoBigChars(char * src){
    int l = strlen(src);
    char ** BigChars = (char**) malloc(l + 1);
    if (!BigChars){ exit(-1);}
    for (int i = 0; i < l; ++i){
        BigChars[i] = atobig(src[i]);
    }
    BigChars[l] = NULL;
    // from static memory, cannot be freed
    char * res = BigChars[0];
    for (int i = 1; i < l; ++i){
        res = combineBigChars(res, BigChars[i]);
    }
    return res;
}
char * path = "./selfs.db";
const int sectionLen = 11;
// if no data, init data first time.

// read self data. return and give it to a scroll list to show.
char ** ReadSelf(int dimension){
    FILE * Read = fopen(path, "rb");
    if (!Read){
        exit(-1);
    }
    char ** marks = (char**) malloc(sectionLen * sizeof(char*));
    int * section = (int*) malloc(sectionLen * sizeof(int));
    // every section map to a dimension
    if (!section || !marks){ exit(-1); }
    for (int i = 0; i < dimension; ++i){
        fread(section, sizeof (int), sectionLen, Read);
    }
    // now section has the data of dimension.
    for (int i = 1; i < sectionLen; ++i){
        char * thisData = combineTwoString(
                myItoa(i),
                DEFAULT,
                combineTwoString(". ",
                                 DEFAULT,
                                 myItoa(section[i]),
                                 DEFAULT),
                DEFAULT);
        marks[i - 1] = thisData;
    }
    marks[sectionLen - 1] = NULL;
    fclose(Read);
    return marks;
}

// This function is used to refresh self
void updateSelf(int dimension, int grade){
    FILE * read = fopen(path, "rb+");
    int * section = (int*) malloc(sectionLen * sizeof (int));
    for (int i = 0; i < dimension - 1; ++i){
        fread(section, sizeof (int), sectionLen, read);
    }
    unsigned here = ftell(read);
    // read to the memory
    fread(section, sizeof (int), sectionLen, read);
    for (int i = 1; i < sectionLen; ++i){
        // the first number is dimension, not to compare
        if (section[i] < grade){
            // find a lower record
            for (int j = sectionLen - 1; j > i; --j){
                section[j] = section[j - 1];
            }
            section[i] = grade;
            break;
        }
    }
    fseek(read, here, SEEK_SET);
    fwrite(section, sizeof (int), sectionLen, read);
    fclose(read);
    free(section);
}

typedef struct checkStruct{
    int ** BoomLayout; // the boom layout array of the area
    int ** HaveChecked; // a map of if the block has been checked
    struct checkStruct ** Meta; // all checkStructs
    Widget ** Booms; // all blocks(include boom and safes)
    Widget * o;
    int row; // current row
    int colum; // current colum
    int dimension;
    int ThenBg; // BG color after check
    int * score;
}checkStruct;

checkStruct CreateMeta(int ** BoomLayout, int** HavaChecked, checkStruct ** Meta, Widget ** Booms, int row, int colum, int dimension, int ThenBg, Widget * o, int * score){
    checkStruct * nm = (checkStruct *) malloc(sizeof (checkStruct));
    if (!nm){ exit(-1);}
    nm->BoomLayout = BoomLayout;
    nm->HaveChecked = HavaChecked;
    nm->Meta = Meta;
    nm->Booms = Booms;
    nm->row = row;
    nm->colum = colum;
    nm->dimension = dimension;
    nm->ThenBg = ThenBg;
    nm->o = o;
    nm->score = score;
    return *nm;
}

// when click the button, change it's state
void check(Widget w, checkStruct * data){
    static int firstFlag = 1; // if the first click?
    static int gameOver = 0;
    // if has been checked and it is a boom
    if (data->HaveChecked[data->row][data->colum]){
        return;
    }
    data->HaveChecked[data->row][data->colum] = 1;
    if (data->BoomLayout[data->row][data->colum]){
        // if touch the boom
        if (!firstFlag) {
            if (!gameOver) {
                gameOver = 1;
                GetOkay(combineTwoString("\n\n\n\n\n\n\nGame Over, you got \n\n\n\n\n\n\n", DEFAULT, myItoa(*data->score), DEFAULT));
                updateSelf(data->dimension, *data->score);
            }
            SetBgColor(w, RED);
            SetLabel(w, "\n \\|/ \n -O- \n /|\\ \n\n");
            SetFgColor(w, YELLOW);
            // update o
            if (!data->row && !data->colum){
                SetBgColor(*data->o, RED);
                ClearDrawArea();
            }
            ClearDrawArea();
            // check all blocks
            for (int i = 0; i < data->dimension; ++i) {
                for (int j = 0; j < data->dimension; ++j) {
                    check(data->Booms[i][j], &data->Meta[i][j]);
                }
            }
            return;
        } else{
            // if the first time to touch the boom
            data->BoomLayout[data->row][data->colum] = 0;
            int total = data->dimension * data->dimension;
            int has = 0;
            for (int i = 0; i < data->dimension; ++i){
                for (int j = 0; j < data->dimension; ++j){
                    if (data->BoomLayout[i][j]){
                        has++;
                    }
                }
            }
            // guarantee there exist at least one safe block after "i":
            for (int i = rand() % (total - has); i < total; ++i){
                if (!data->BoomLayout[i / data->dimension][i % data->dimension]){
                    data->BoomLayout[i / data->dimension][i % data->dimension] = 1;
                    break;
                }
            }
        }
    }
    firstFlag = 0; // the first check resumed
    int total = 0;
    if (data->row >= 1){
        if (data->BoomLayout[data->row - 1][data->colum]) ++total;
        if (data->colum >= 1 && data->BoomLayout[data->row - 1][data->colum - 1]) ++total;
        if (data->colum < data->dimension - 1 && data->BoomLayout[data->row - 1][data->colum + 1]) ++total;
    }
    if (data->row < data->dimension - 1){
        if (data->BoomLayout[data->row + 1][data->colum]) ++total;
        if (data->colum >= 1 && data->BoomLayout[data->row + 1][data->colum - 1]) ++total;
        if (data->colum < data->dimension - 1 && data->BoomLayout[data->row + 1][data->colum + 1]) ++total;
    }
    if (data->colum >= 1 && data->BoomLayout[data->row][data->colum - 1]) ++total;
    if (data->colum < data->dimension - 1 && data->BoomLayout[data->row][data->colum + 1]) ++total;
    if (total){
        if (!gameOver){
            *data->score += total;
        }
        char * wild = atobig(myItoa(total)[0]);
        if (total == 1){
            SetFgColor(w, WHITE);
        }else if(total == 2){
            SetFgColor(w, GREEN);
        } else{
            SetFgColor(w, RED);
        }
        SetLabel(w, wild);
        SetBgColor(w, data->ThenBg);
        if (!data->row && !data->colum){
            SetBgColor(*data->o, data->ThenBg);
        }
        ClearDrawArea();
    }else{
        SetLabel(w, "\n\n\n\n\n");
        SetBgColor(w, data->ThenBg);
        if (!data->row && !data->colum){
            SetBgColor(*(data->o), data->ThenBg);
        }
        if (data->row >= 1){
            check(data->Booms[data->row - 1][data->colum], &data->Meta[data->row - 1][data->colum]);
            if (data->colum >= 1)
                check(data->Booms[data->row - 1][data->colum - 1], &data->Meta[data->row - 1][data->colum - 1]);
            if (data->colum < data->dimension - 1)
                check(data->Booms[data->row - 1][data->colum + 1], &data->Meta[data->row - 1][data->colum + 1]);
        }
        if (data->row < data->dimension - 1){
            check(data->Booms[data->row + 1][data->colum], &data->Meta[data->row + 1][data->colum]);
            if (data->colum >= 1)
                check(data->Booms[data->row + 1][data->colum - 1], &data->Meta[data->row + 1][data->colum - 1]);
            if (data->colum < data->dimension - 1)
                check(data->Booms[data->row + 1][data->colum + 1], &data->Meta[data->row + 1][data->colum + 1]);
        }
        if (data->colum >= 1)
            check(data->Booms[data->row][data->colum - 1], &data->Meta[data->row][data->colum - 1]);
        if (data->colum < data->dimension - 1)
            check(data->Booms[data->row][data->colum + 1], &data->Meta[data->row][data->colum + 1]);
    }
}
typedef struct FireInfoStruct{
    int dimension; // dimension of this game.
    void (*initWidgets)(int dimension, int * score);
    Widget (*initWindow)(int w, int h);
    int * score;
} FireInfoStruct;

FireInfoStruct * createFireInfoStruct(int dimension, void initWidgets(int dimension, int * score), Widget (*initWindow)(int w, int h)){
    FireInfoStruct * nf = (FireInfoStruct*) malloc(sizeof (FireInfoStruct));
    nf->dimension = dimension;
    nf->initWindow = initWindow;
    nf->initWidgets = initWidgets;
    nf->score = (int*) malloc(sizeof (int));
    if (!nf->score){ exit(-1);}
    *nf->score = 0;
    return nf;
}

// fire a game, callback of fire button
void fire(Widget w, FireInfoStruct * data){
    // open a new window
    *data->score = 0;
    Widget game = MakeWindow(
    combineTwoString(combineTwoString(
                    myItoa(data->dimension),
                    DEFAULT,
                    "x", DEFAULT
                    ),
                     DEFAULT,
                     myItoa(data->dimension),
                     DEFAULT
                    ),
                    SAME_DISPLAY,
                    EXCLUSIVE_WINDOW);
    Widget NewArea = data->initWindow(75 * data->dimension, 100 * data->dimension);
    data->initWidgets(data->dimension, data->score);
    MainLoop();
}
typedef struct ItemStruct{
    int value;
    char * valueStr;
    Widget * OwnerItem;
    Widget * RevealLabel; // reveal the info about the menu's checking condition
    Widget * Label;
    void (*initWidgets)(int dimension, int * score);
    Widget (*initWindow)(int w, int h);
}ItemStruct;

ItemStruct * CreateItemStruct(int value, char * valueStr, Widget * OwnerItem, Widget * RevealLabel, Widget * Label, void (*initWidgets)(int dimension, int * score), Widget (*initWindow)(int w, int h)){
    ItemStruct * ni = (ItemStruct*) malloc(sizeof(ItemStruct));
    if (!ni){ exit(-1);}
    ni->value = value;
    ni->valueStr = valueStr;
    ni->OwnerItem = OwnerItem;
    ni->RevealLabel = RevealLabel;
    ni->Label = Label;
    ni->initWidgets = initWidgets;
    ni->initWindow = initWindow;
    return ni;
}

void choose(Widget w, ItemStruct * data) {
    static Widget * LastCheck = NULL;
    static char ** scoresList = NULL;
    static Widget * list = NULL;
    static Widget * Fire = NULL;
    static int width = 100;
    static int height = 200;
    static char ** listChars = NULL;
    static char * labelChars = NULL;
    // if not been chosen, choose it
    if (!GetMenuItemChecked(w)) {

        // if there exist a last chosen one
        if (LastCheck) {
            SetMenuItemChecked(*LastCheck, False);
            for (int i = 0; i < 10; ++i){
                free(listChars[i]);
            }
            free(listChars);
            free(labelChars);
            listChars = ReadSelf(data->value);
            ChangeScrollList(*list, listChars);
        } else{
            // else, do initialization stuff
            listChars = ReadSelf(data->value);
            FireInfoStruct * fi = createFireInfoStruct(data->value, data->initWidgets, data->initWindow);
            list = (Widget*) malloc(sizeof (Widget));
            Fire = (Widget*) malloc(sizeof (Widget));

            *list =  MakeScrollList(listChars, width, height, NULL, NULL);
            *Fire = MakeButton(" +--  -+-  ++   +-- \n +-    |   ++   +-- \n |    -+-  |\\   +-- ", (ButtonCB) fire, fi);

            SetFgColor(*list, GREEN);
            SetFgColor(*Fire, GetRGBColor(250, 250, 250));
            SetBgColor(*list, GetRGBColor(140, 140, 220));
            SetBgColor(*Fire, GetRGBColor(150, 150, 150));


            SetWidgetPos(*list, PLACE_RIGHT, *data->RevealLabel, PLACE_UNDER, *data->Label);
            SetWidgetPos(*Fire, PLACE_UNDER, *list, NO_CARE, NULL);
            ClearDrawArea();
        }
        // update dimension info
        labelChars = combineBigChars(
                data->value > 10 ? atobig(data->valueStr[0]) : atobig('0'),
                data->value > 10 ? atobig(data->valueStr[1]) : atobig(data->valueStr[0])
        );
        SetLabel(*data->RevealLabel, labelChars);
        LastCheck = data->OwnerItem;
        SetMenuItemChecked(w, True);
    }
}
Widget initWindow(int width, int height){
    Widget * MainArea = (Widget*) malloc(sizeof (Widget));
    if (!MainArea){ exit(-1);}
    *MainArea = MakeDrawArea(width, height, NULL, NULL);
    // the main painting context
    ShowDisplay();
    int bgColor = GetRGBColor(100,100,120);// set the main display
    GetStandardColors();
    SetBgColor(*MainArea, bgColor);
    ClearDrawArea();
    return *MainArea;
}

Widget * initWines(int dimension, Widget * toUnder, int OriginBg, int ThenBg, int * score);
// init Widgets
void initWidgets(int dimension, int * score){
    int titleColor = GetRGBColor(100,100,50);
    Widget title;
    if (dimension > 5) {
        title = MakeLabel("\n\n\n\n\nLet's find out all Mines!\n\n\n\n\n");
    }else{
        title = MakeLabel("\nfind Mines!\n");
    }
    SetBgColor(title, titleColor);
    Widget * wines = initWines(dimension, &title,  GetRGBColor(150, 150, 150), GetRGBColor(100, 100, 100), score);
    Widget AsideForm = MakeForm(TOP_LEVEL_FORM);
    SetForm(AsideForm);

    SetWidgetPos(AsideForm, PLACE_RIGHT, *wines, PLACE_UNDER, title);
    Widget list = MakeScrollList(ReadSelf(dimension),  10 * dimension, 60 * dimension, NULL, NULL);
    Widget * scoreShow =(Widget*)malloc(sizeof(Widget));
    *scoreShow = MakeLabel(atobig(myItoa(*score)[0])); // used to show the score.

    SetFgColor(list, GREEN);
    SetFgColor(*scoreShow, YELLOW);
    SetBgColor(list, GetRGBColor(140, 140, 220));
    SetBgColor(*scoreShow, GetRGBColor(200, 200, 250));
    SetWidgetPos(*scoreShow, PLACE_RIGHT, list, NO_CARE, NULL);
}

void initGameInfo(){
    // choose a difficulty
    Widget * title = (Widget*) malloc(sizeof(Widget));
    Widget * chooseDifficulty = (Widget*) malloc(sizeof (Widget));
    Widget * RevealLabel = (Widget*) malloc(sizeof (Widget));

    *RevealLabel = MakeLabel(combineBigChars("\\   /\n \\ / \n  X  \n / \\ \n/   \\", "\\   /\n \\ / \n  X  \n / \\ \n/   \\"));
    *title = MakeLabel("     |===============\\\\\\          \n     |================\\\\\\         \n     |=================\\\\\\        \n     |===|              \\\\\\       \n     |===|               \\\\\\      \n     |===|                |||        \n     |===|                |||        \n     |===|                |||        \n     |===|                |||        \n     |===|               ///         \n     |===|              ///          \n     |===|=============///           \n     |===|============///            \n     |===|===========///             ");
    *chooseDifficulty = MakeMenu("     |===============\\\\\\          \n     |================\\\\\\         \n     |=================\\\\\\        \n     |===|              \\\\\\       \n     |===|               \\\\\\      \n     |===|                |||        \n     |===|                |||        \n     |===|                |||        \n     |===|                |||        \n     |===|               ///         \n     |===|              ///          \n     |===|=============///           \n     |===|============///            \n     |===|===========///             ");

    SetWidgetPos(*title, PLACE_RIGHT, *chooseDifficulty, NO_CARE, NULL);
    SetWidgetPos(*RevealLabel,  PLACE_UNDER, *title, PLACE_RIGHT, *chooseDifficulty);

    SetBgColor(*chooseDifficulty, GetRGBColor(100, 100, 180));
    SetBgColor(*title, GetRGBColor(130, 130, 130));
    SetBgColor(*RevealLabel, GetRGBColor(255, 192, 203));
    SetFgColor(*chooseDifficulty, YELLOW);
    SetFgColor(*title, WHITE);
    SetFgColor(*RevealLabel, GetRGBColor(30, 144, 255));
    ClearDrawArea();
    int dimensionBound[2] = {3, 30};
    for (int i = dimensionBound[0]; i <= dimensionBound[1]; ++i){
        char * valueStr = myItoa(i);
        Widget * fen = (Widget *) malloc(sizeof(Widget));
        if (!fen){exit(-1);}
        *fen = MakeMenuItem(
                *chooseDifficulty,
                valueStr,
                (ButtonCB) choose,
                CreateItemStruct(
                        i,
                        valueStr ,
                        fen,
                        RevealLabel,
                        title,
                        initWidgets,
                        initWindow
                ));
    }
}

// init boom positions. if the (x, y) has an wine, the value will be 1, otherwise 0.
int ** initBooms(int dimension){
    srand((unsigned long)initWines);
    int total = dimension * dimension;
    int boomNumber;
    if ( total * 2 / 35) {
        boomNumber = rand() % (total * 2 / 35) + total / 7;
    } else{
        boomNumber = total / 7;
    }
    int * ifBoom = (int*) malloc(total * sizeof (int));
    if (!ifBoom){ exit(-1);}
    memset(ifBoom, 0, total * sizeof (int));
    for (int i = 0; i < boomNumber; ++i){
        ifBoom[i] = 1;
    }
    // shuffle alg ri
    for (int i = total - 1; i > 0; --i){
        int swapSub = rand() % (i + 1);
        int temp = ifBoom[i];
        ifBoom[i] = ifBoom[swapSub];
        ifBoom[swapSub] = temp;
    }

    int ** returnstuff = (int**) malloc(dimension * sizeof (int*));
    if (!returnstuff){ exit(-1);}
    for (int i = 0; i < dimension; ++i){
        returnstuff[i] = (int *) malloc(dimension * sizeof (int));
        if (!returnstuff[i]){ exit(-1);}
    }
    for (int i = 0; i < dimension * dimension; ++i){
        returnstuff[i / dimension][i % dimension] = ifBoom[i];
    }
    return returnstuff;
}

// init all wines
Widget * initWines(int dimension, Widget * toUnder, int OriginBg, int ThenBg, int * score){
    Widget * Parent = (Widget *) malloc(sizeof (Widget));
    *Parent = MakeForm(TOP_LEVEL_FORM);
    // the o is used to balance layout
    Widget * o = (Widget*) malloc(sizeof (Widget));
    Widget ** Wines = (Widget**) malloc(dimension* sizeof (Widget*));
    int ** haveChecked = (int**) malloc(dimension * sizeof (int*)); // avoid recursive calling for check()
    checkStruct ** Meta = (checkStruct**) malloc(dimension* sizeof (checkStruct*));

    if (!Wines || !Meta || !haveChecked || !o){ exit(-1);}
    for (int i = 0; i < dimension; ++i){
        Wines[i] = (Widget*) malloc(dimension * sizeof (Widget));
        Meta[i] = (checkStruct*) malloc(dimension * sizeof (checkStruct));
        haveChecked[i] = (int*) malloc(dimension * sizeof (int));
        for (int j = 0; j < dimension; ++j){
            haveChecked[i][j] = 0;
        }
        if (!Wines[i] || !Meta[i] || !haveChecked[i]){ exit(-1);}
    }

    SetWidgetPos(*Parent, PLACE_UNDER, *toUnder, NO_CARE, NULL);
    SetForm(*Parent);
    // boom lay out
    int ** boomLayout = initBooms(dimension);

    Meta[0][0] = CreateMeta(boomLayout, haveChecked, Meta, Wines, 0, 0,  dimension, ThenBg, o, score);
    Wines[0][0] = MakeButton("\n\n\n     \n\n\n", (ButtonCB) check, &Meta[0][0]);
    SetBgColor(Wines[0][0], OriginBg);
    for (int i = 0; i < dimension; ++i){
        for (int j = 0; j < dimension; ++j){
            if (!i && !j){
                SetWidgetPos(Wines[i][j], NO_CARE, NULL,NO_CARE, NULL);
                continue;
            }
            Meta[i][j] = CreateMeta(boomLayout, haveChecked, Meta, Wines, i, j, dimension, ThenBg, o, score);
            Wines[i][j] = MakeButton("\n\n\n     \n\n\n", (ButtonCB) check, &Meta[i][j]);
            SetBgColor(Wines[i][j],  OriginBg);
            ClearDrawArea();
            SetWidgetPos(
                    Wines[i][j],
                    j ? PLACE_RIGHT : NO_CARE,
                    j ? Wines[i][j - 1] : NULL,
                    j ? i ? PLACE_UNDER : NO_CARE : PLACE_UNDER,
                    j ? i ? Wines[i - 1][j] : NULL : Wines[i - 1][j]
                    );
        }
        *o = MakeButton("", NULL, NULL);
        SetBgColor(*o, OriginBg);
        ClearDrawArea();
    }
    return Parent;
}


int main(int argc, char **argv){
    OpenDisplay(argc, argv);
    initWindow(500, 500);
    initGameInfo();
    MainLoop();
}
