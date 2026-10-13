#include <iostream>
#include <string>
#include <windows.h>

#pragma region Backgrounds
// Base Background class
class Background {
protected:
	std::string theme;
public:
	Background() {}
	virtual void getTheme() = 0;
};

// Derived Light Background class
class LightBkgd : public Background {
public:
	LightBkgd(HANDLE hConsole) {
		SetConsoleTextAttribute(hConsole, 240);
		std::cout << "Making the background white\n";
		theme = "light";
    }

	void getTheme() {
		std::cout << "This is a part of the light theme\n";
	}
};

// Derived Dark Background class
class DarkBkgd : public Background {
public:
	DarkBkgd(HANDLE hConsole) {
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "Making the background black\n";
		theme = "dark";
	}

	void getTheme() {
		std::cout << "This is a part of the dark theme\n";
	}
};
#pragma endregion Background

#pragma region Text
// Base Text class
class Text {
protected:
	std::string theme;
public:
	Text() {}
	virtual void message(HANDLE hConsole) = 0;
};

// Derived Black Text class
class BlackText : public Text {
public:
	BlackText(HANDLE hConsole) {
		SetConsoleTextAttribute(hConsole, 240);
		theme = "light";
		std::cout << "Making the text black\n";
	}

	void message(HANDLE hConsole) {
		SetConsoleTextAttribute(hConsole, 240);
		std::cout << "This is the default font from the light theme\n";
	}
};

// Derived White Text class
class WhiteText : public Text {
public:
	WhiteText(HANDLE hConsole) {
		SetConsoleTextAttribute(hConsole, 15);
		theme = "dark";
		std::cout << "Making the text white\n";
	}

	void message(HANDLE hConsole) {
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "This is the default font for the dark theme\n";
	}
};

// Derived Dark Green Text class
class DarkGreenText: public Text {
	WhiteText(HANDLE hConsole) {
		SetConsoleTextAttribute(hConsole, 242);
		theme = "light";
		std::cout << "Making the text dark green\n";
	}

	void message(HANDLE hConsole) {
		SetConsoleTextAttribute(hConsole, 242);
		std::cout << "This is the default font for the light theme\n";
	}
};

// Derived Light Green Text class
class LightGreenText: public Text {
	WhiteText(HANDLE hConsole) {
		SetConsoleTextAttribute(hConsole, 10);
		theme = "dark";
		std::cout << "Making the text light green\n";
	}

	void message(HANDLE hConsole) {
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "This is the default font for the dark theme\n";
	}
};

#pragma endregion Text

#pragma region Factories
// Base Factory
class ThemeFactory {
public:
	virtual Background* setBackground(HANDLE hConsole) = 0;
	virtual Text* getDefaultText(HANDLE hConsole) = 0;
    virtual Text* getGreenText(HANDLE hConsole) = 0;
};

// Derived Light Theme Factory which pairs the white background with darker text
class LightFactory : public ThemeFactory {
public:
	Background * setBackground(HANDLE hConsole) {
		return new LightBkgd(hConsole);
	}

	Text * getDefaultText(HANDLE hConsole) {
		return new BlackText(hConsole);
	}

    Text * getGreenText(HANDLE hConsole) override {
        return new DarkGreenText();
    }
};

// Derived Dark Theme Factory which pairs the black background with lighter text
class DarkFactory : public ThemeFactory {
public:
	Background * setBackground(HANDLE hConsole) {
		return new DarkBkgd(hConsole);
	}

	Text * getDefaultText(HANDLE hConsole) {
		return new WhiteText(hConsole);
	}

    Text * getGreenText(HANDLE hConsole) override {
        return new LightGreenText();
    }
};
#pragma endregion Factories

int main() {
	// Configure console variables and colours
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 30);

	ThemeFactory* app;
	int choice;

	std::cout << "Select a theme: \n";
	std::cout << "1: Light\n";
	std::cout << "2: Dark\n";
	std::cout << "Selection: \n";
	std::cin >> choice;
	std::cout << std::endl;

	// Initiate the correct factory based on user input
	switch (choice)
	{
	case 1:
		app = new LightFactory;
		break;
	case 2:
		app = new DarkFactory;
		break;
	default:
		std::cout << "Invalid Selection\n";
		app = nullptr;
		break;
	}

	// Get the correct objects based on factory selected
	if (app) {
		Background* appBkgd = app->setBackground(hConsole);
		Text *appDefaultText = app->getDefaultText(hConsole);

		appDefaultText->message(hConsole);
	}

	std::cout << std::endl;
	//system("pause");
}