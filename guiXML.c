#include <stdbool.h>

#include <stdio.h>

#include <stdlib.h>

#include "xml.c/src/xml.h"

#include "parser.h"

struct xml_node* root;

int lectura() {
    FILE * stream;
    stream = fopen("file.xml", "r");
    struct xml_document* document = xml_open_document(stream);
    
    if (!document) {
		printf("Could parse document\n");
		exit(-1);
	} else {
        printf("fichero leido con exito\n");
    }
    
    root = xml_document_root(document);
}

char* LeerNodo(int index){
   
    struct xml_node* nodo0 = xml_node_child(root, index);  //el segundo parametro (el numero) es el nodo que queremos leer, probar con 1, 2...
	struct xml_string* contenidoNodo0 = xml_node_content(nodo0);

	char* contenidoNodo0_S = calloc(xml_string_length(contenidoNodo0) + 1, sizeof(char));

	xml_string_copy(contenidoNodo0, contenidoNodo0_S, xml_string_length(contenidoNodo0));

    //liberar memoria
	free(contenidoNodo0);

    return contenidoNodo0_S;
}

int LeerAtributos(int index, int indexAtributos){
    struct xml_node* nodo = xml_node_child(root, index);

    struct xml_string* atributoContentNodo = xml_node_attribute_content(nodo, indexAtributos);

    char* atributoContentNodo_S = calloc(xml_string_length(atributoContentNodo) + 1, sizeof(char));

    xml_string_copy(atributoContentNodo, atributoContentNodo_S, xml_string_length(atributoContentNodo));

    free(atributoContentNodo);

    return *atributoContentNodo_S;
}

int numIconos() {
    return xml_node_children(root);
}

struct Icon leerIcono(int index) {
    struct Icon icon;
    icon.file = LeerNodo(index);
    icon.text = LeerAtributos(index, 2);
    icon.posx = atoi(LeerAtributos(index, 0));
    icon.posy = atoi(LeerAtributos(index, 1));

    return icon;
}