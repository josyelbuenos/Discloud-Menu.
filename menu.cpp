#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>

void set_utf8_encoding() {
    SetConsoleOutputCP(CP_UTF8); // Configura a saida para UTF-8
    SetConsoleCP(CP_UTF8);       // Configura a entrada para UTF-8
}

using namespace std;

// ANSI escape codes para cores
const string RESET = "\033[0m";
const string CYAN = "\033[36m";
const string YELLOW = "\033[33m";
const string MAGENTA = "\033[35m\033[1m"; // Texto brilhante
const string GREEN = "\033[32m";
const string RED = "\033[31m";

// Limpar a tela
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Exibir cabeçalho estilizado
void print_header(const string& title) {
    clear_screen();
    const int width = 60; // Largura fixa do banner
    string centered_title = "DISCLOUD MENU";
    int padding_title = (width - centered_title.size()) / 2;
    string centered_subtitle = title;
    int padding_subtitle = (width - centered_subtitle.size()) / 2;

    cout << CYAN << string(width, '*') << "\n";
    cout << CYAN << "*" << string(width - 2, ' ') << "*" << "\n";
    cout << CYAN << "*" << string(padding_title, ' ') << MAGENTA << centered_title << string(width - padding_title - centered_title.size() - 2, ' ') << CYAN << "*" << "\n";
    cout << CYAN << "*" << string(padding_subtitle, ' ') << YELLOW << centered_subtitle << string(width - padding_subtitle - centered_subtitle.size() - 2, ' ') << CYAN << "*" << "\n";
    cout << CYAN << "*" << string(width - 2, ' ') << "*" << "\n";
    cout << CYAN << string(width, '*') << "\n" << RESET;
}

// Exibir menu principal
void print_menu() {
    cout << GREEN << "Escolha uma opcao:\n" << RESET;
    cout << CYAN << "1. " << YELLOW << "Visualizar informacoes do usuario\n";
    cout << CYAN << "2. " << YELLOW << "Upload de aplicacao\n";
    cout << CYAN << "3. " << YELLOW << "Terminal da aplicacao\n";
    cout << CYAN << "4. " << YELLOW << "Gerenciar (start, stop, restart, status, logs, etc.)\n";
    cout << CYAN << "5. " << YELLOW << "Realizar backup\n";
    cout << CYAN << "6. " << YELLOW << "Excluir aplicacao\n";
    cout << CYAN << "7. " << YELLOW << "Login\n";
    cout << CYAN << "8. " << YELLOW << "Sair\n";
    cout << CYAN << string(60, '*') << "\n" << RESET;
}

// Executar comando no terminal
void execute_command(const string& command, const string& description) {
    cout << YELLOW << "\nExecutando: " << GREEN << description << RESET << endl;
    system(command.c_str());
    cout << CYAN << "\nPressione Enter para continuar..." << RESET;
    cin.ignore();
}

// Submenu de gerenciamento
void submenu_team() {
    print_header("Gerenciar");
    cout << CYAN << "1. " << YELLOW << "Parar aplicativos\n";
    cout << CYAN << "2. " << YELLOW << "Iniciar aplicativos\n";
    cout << CYAN << "3. " << YELLOW << "Reiniciar aplicativos\n";
    cout << CYAN << "4. " << YELLOW << "Status dos aplicativos\n";
    cout << CYAN << "5. " << YELLOW << "Visualizar logs\n";
    cout << CYAN << "6. " << YELLOW << "Voltar ao menu principal\n" << RESET;

    cout << GREEN << "Escolha uma opcao: " << RESET;
    string choice;
    cin >> choice;

    if (choice == "1") execute_command("discloud stop", "Parando aplicativos");
    else if (choice == "2") execute_command("discloud start", "Iniciando aplicativos");
    else if (choice == "3") execute_command("discloud restart", "Reiniciando aplicativos");
    else if (choice == "4") execute_command("discloud status", "Verificando status dos aplicativos");
    else if (choice == "5") execute_command("discloud logs", "Visualizando logs");
}

void login() {
    execute_command("discloud login", "Executando login no Discloud");
}

// Funcao principal
int main() {
    while (true) {
        print_header("Menu Principal");
        print_menu();

        cout << GREEN << "Escolha uma opcao: " << RESET;
        string choice;
        cin >> choice;

        if (choice == "1") execute_command("discloud userinfo", "Visualizando informacoes do usuario");
        else if (choice == "2") execute_command("discloud upload", "Realizando upload de aplicacao");
        else if (choice == "3") execute_command("discloud terminal", "Acessando terminal da aplicacao");
        else if (choice == "4") submenu_team();
        else if (choice == "5") execute_command("discloud backups", "Realizando backup");
        else if (choice == "6") execute_command("discloud delete", "Excluindo aplicacao");
        else if (choice == "7") login();
        else if (choice == "8") {
            cout << RED << "\nSaindo do programa... Ate logo!\n" << RESET;
            break;
        } else {
            cout << RED << "\nOpcao invalida! Tente novamente.\n" << RESET;
        }

        cin.ignore(); // Limpar o buffer
    }

    return 0;
}
