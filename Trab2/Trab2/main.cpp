#include <iostream>
#include "dominios.h"
#include "entidades.h"
#include "controladoras.h"
#include "curses.h"
#include <vector>

using namespace std;

int main(){
	int choice,linha, coluna, menuLinha, menuColuna, tam_string, posMenu, proxMenu, highlight = 0;
	vector<string> choices= { "Pesquisar Evento","Cadastrar", "Entrar" };
	ControladoraApresentacaoEventos CtrApreEve;


	initscr();
	noecho();

	getmaxyx(stdscr, linha, coluna);
	keypad(stdscr, true);

	while (true)
	{
		for (int i = 0; i < 3; i++) {
			if (i == highlight)
				wattron(stdscr, WA_STANDOUT);
			tam_string = strlen(choices.at(i).c_str());
			mvwprintw(stdscr, (linha / 2) + (i - 1), (coluna - tam_string) / 2, choices[i].c_str());
			wattroff(stdscr, WA_STANDOUT);
		}

		choice = wgetch(stdscr);
		
		switch (choice)
		{
		case KEY_UP:
			highlight--;
			if (highlight == -1)
				highlight = 0;
			break;
		case KEY_DOWN:
			highlight++;
			if (highlight == 3)
				highlight = 2;
			break;
		default:
			break;
		}

		if (choice == 10) {
			break;
		}
	}
	clear();
	switch (highlight)
	{
	case 0:
		tam_string = strlen(choices.at(highlight).c_str());
		mvwprintw(stdscr, 0 ,(coluna - tam_string)/2, choices.at(highlight).c_str());
		wrefresh(stdscr);
		CtrApreEve.executar();
		break;
	case 1:
		tam_string = strlen(choices.at(highlight).c_str());
		mvwprintw(stdscr, 0, (coluna - tam_string) / 2, choices.at(highlight).c_str());
		wrefresh(stdscr);
		break;
	case 2:
		tam_string = strlen(choices.at(highlight).c_str());
		mvwprintw(stdscr, 0, (coluna - tam_string) / 2, choices.at(highlight).c_str());
		wrefresh(stdscr);
		break;
	default:
		break;
	}

	getch();

	return 0;
}
