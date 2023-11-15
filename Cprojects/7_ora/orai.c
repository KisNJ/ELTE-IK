#include <stdio.h>


int count = 5; // globális
static int static_count; // csak ebben a fordítási egységben látszik externnel hiba

int main() {
    func();
    func();
    func(); // i = 8 a static miatt
}

void func() {
    static int i = 5; // a függvény után nem szabadul fel az érték
    i++;

    auto int j = 4; // ez az alapértelmezett nem kell az auto
    register int alma = 10; // egy regiszterben tárold

    //DNW
    //printf("address of alma: %p", &alma);
}

// másik fájl gcc 1.c 2.c
extern int count; // e nélkül nem működne, nem lesz itt memória foglalás
extern int static_count; // hiba a globális static csak az adott fájlban elérhető
// int count; ez is jó lenne, de externnel egyértelműbb
// int count = 15; // hiba többször deklarálunk
void print() {
    puts(count);
}

// python teljes scopera vonatkozik a láthatóság
a = 6
name="Mao"
def pr():
	print(a) #EZ JÓ	
	global name #ne hozzon létre lokális változót, mert alapértelmezetten az lenne
	name = "ASD"

def pr():
	print(a) #EZ HIBA
	a = 8

x=7
def fn():
	x = 9
	def inner():
		nonlocal x
		x += 1 #x == 10
