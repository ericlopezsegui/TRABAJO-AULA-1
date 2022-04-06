int lectura();
char* LeerNodo(int index);
int LeerAtributos(int index, int indexAtributos);
int numIoncos();
struct Icon ReadIcon(int index);

struct Icon {
    char* file;
    char* text;
    int posx;
    int posy;
};