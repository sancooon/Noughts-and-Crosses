#include "KeyMap.h"
#include <map>

using namespace std;
map<char, gridCoord> keyBinds;

void initializeKeyBind() {
	keyBinds.insert(pair<char, gridCoord>('a', { 0, 0 }));
	keyBinds.insert(pair<char, gridCoord>('A', { 0, 0 }));
	keyBinds.insert(pair<char, gridCoord>('b', { 0, 1 }));
	keyBinds.insert(pair<char, gridCoord>('B', { 0, 1 }));
	keyBinds.insert(pair<char, gridCoord>('c', { 0, 2 }));
	keyBinds.insert(pair<char, gridCoord>('C', { 0, 2 }));
	keyBinds.insert(pair<char, gridCoord>('d', { 1, 0 }));
	keyBinds.insert(pair<char, gridCoord>('D', { 1, 0 }));
	keyBinds.insert(pair<char, gridCoord>('e', { 1, 1 }));
	keyBinds.insert(pair<char, gridCoord>('E', { 1, 1 }));
	keyBinds.insert(pair<char, gridCoord>('f', { 1, 2 }));
	keyBinds.insert(pair<char, gridCoord>('F', { 1, 2 }));
	keyBinds.insert(pair<char, gridCoord>('g', { 2, 0 }));
	keyBinds.insert(pair<char, gridCoord>('G', { 2, 0 }));
	keyBinds.insert(pair<char, gridCoord>('h', { 2, 1 }));
	keyBinds.insert(pair<char, gridCoord>('H', { 2, 1 }));
	keyBinds.insert(pair<char, gridCoord>('i', { 2, 2 }));
	keyBinds.insert(pair<char, gridCoord>('I', { 2, 2 }));
}