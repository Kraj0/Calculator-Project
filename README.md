# Calculator Project:
Project includes such tools as CMake, GoogleTest.

You can run Gtests without using cmake, by opening .sln file from main directiory, then right click
left bar Conversions_Gtest - Debug - Start New Instance.

If u have installed Cmake (min version 3.6.2) on your computer you can also
build project using this tool. (Personally i used cmake-gui version) CMakeLists.txt is in the main directory. I suggest using 
build directiory as the place for output files. You can run the program without using Cmake
just by opening .sln file in main directory. Calculator only accepts integers as input.

#Uwagi do projektu (studia):
W pliku conversions.cpp znajdują się komentarze opisujące co robią i jak powstały znajdujące się tam funkcje,
używane do konwersji liczb, Cmake lista została napisana na podstawie przykładowej listy znajdującej się w książce:
Cyganek B.: Programowanie w języku C++. Wprowadzenie dla inżynierów. PWN, 2023. 
Została ona jednak zmodyfikowana dla danego projektu.
Wiedzę dotyczącą użycia MFC zdobyłem używając głownie tego artykułu:
https://learn.microsoft.com/pl-pl/cpp/mfc/reference/creating-an-mfc-application?view=msvc-170 
. Sporadycznie również zadawałem pytania narzędziu ChatGpt, jednak w większości jego odpowiedzi
były nie do końca trafne, nie działały na konkretnym przykładzie więc finalnie miał on mały wpływ na projekt.
Kompletnie nie poradził sobie z cmakelistą, mfc pisałem na podstawie dokumentacji biblioteki oraz ze strony
microsoftu. Jedynie lekko pomógł podczas pisania kodu, gdy przeklejałem odpowiedni error i pytałem się chata
z czego on wynika. ChatGpt napisał mi również przykładowe GoogleTesty jednak w moim odczuciu były one mało sensowne
i mało dokładne więc przerobiłem je na własne od nowa.  W katalogu projektu również znajduje się dokumentacja.
