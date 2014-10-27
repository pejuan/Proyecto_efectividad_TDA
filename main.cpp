/* 
 * File:   main.cpp
 * Author: Jose Alberto Pejuan
 *
 * Created on 25 de octubre de 2014, 01:00 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include "tdalist.h"
#include "fsarraylist.h"
#include "cursor.h"
#include "object.h"
#include "integer.h"
#include "slinkedlist.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
	TDAList* lista;
	int pos,elemento;
	clock_t initial,final;
	//lista = new fsarrayList(5000);
	//lista = new cursor(5000);
	lista = new SLinkedList();
	srand(time(0));
	for (int i = 0; i < 5000; ++i){
		pos = (rand() % (int)(lista->size()+1));
		elemento = rand()%5000;
		lista->insert(new Integer(elemento),pos);
		
		//final = clock();
		//cout<<final<<" ";
	}
	/*initial = clock();
	Object* e;
	cout<<"antes for grande"<<endl;
	for (int i = 0; i < 5000; ++i)
	{
		
		
		pos = (rand() % (int)(lista->size()+1));
		e = lista->get(pos);
		final = clock()-initial;
		cout<<final<<" ";


	}*/

	cout<<"SIZE:"<<lista->size()<<endl;
	delete lista;
    return 0;
}

