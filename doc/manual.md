---
title: "Ćwiczenie 1: Odczyt i zapis GPIO"
subtitle: "Instrukcja laboratorium"
footer-left: "Instrukcja laboratorium"
author: [Mariusz Chilmon <<mariusz.chilmon@ctm.gdynia.pl>>]
lang: "pl"
titlepage: yes
titlepage-logo: "logo.png"
logo-width: "70mm"
colorlinks: yes
header-includes: |
  \usepackage{awesomebox}
...

> Nothing is so obvious that it's obvious… The use of the word 'obvious' indicates the absence of a&nbsp;logical argument.
>
> — _Errol Morris_

# Cel ćwiczenia

Celem ćwiczenia jest zapoznanie się z:

* budową cyfrowych portów I/O, czyli GPIO (_General-Purpose Input/Output_),
* podstawowymi rejestrami sterującymi tymi portami,
* operatorami bitowymi.

# Uruchomienie programu wyjściowego

1. Podłącz płytkę _WPSH209_ do _Arduino Uno_.
1. Zbuduj program i wgraj do mikrokontrolera.
1. Zweryfikuj, czy dioda LED `D2` zaświeciła się.

\awesomebox[purple]{2pt}{\faMicrochip}{purple}{Dioda \lstinline{D1} mruga po uruchomieniu urządzenia i w trakcie programowania, gdyż jest używana przez bootloader, który bierze również udział w programowaniu \textit{Arduino Uno}.}

\awesomebox[purple]{2pt}{\faMicrochip}{purple}{Zauważ, że diodę zaświeca stan niski, czyli logiczne \lstinline{0}. Wynika to z tego, że jedna nóżka diody (anoda) podłączona jest na stałe do dodatniej szyny zasilania, a do zaświecenia potrzebne jest jeszcze podłączenie ujemnej szyny zasilania do drugiej nóżki (katody).}

\awesomebox[violet]{2pt}{\faBook}{violet}{Zapoznaj się z opisem portów I/O w nocie katalogowej mikrokontrolera, w szczególności rejestru \lstinline{DDR} (\textit{Data Direction Register}), decydującego o kierunku poszczególnych pinów w porcie, tj. konfigurującego piny jako wejścia lub wyjścia.}

\awesomebox[teal]{2pt}{\faCode}{teal}{Po wskazaniu kursorem makra \lstinline{_BV()} zobaczysz jego rozwinięcie. Zwróć uwagę na wykorzystanie operatora przesunięcia bitowego \lstinline{<<} w celu ustawienia bitu o zadanym numerze.}

# Zadanie podstawowe

## Konfiguracja sprzętowa

1. Załóż zworkę `J2`.

\awesomebox[purple]{2pt}{\faMicrochip}{purple}{Zauważ, że wciśnięcie przycisku zwiera pin mikrokontrolera do ujemnej szyny zasilania, więc znów stanem aktywnym okazuje się \lstinline{0}.}

## Wymagania funkcjonalne

Zmodyfikuj procedurę inicjalizacji GPIO `gpioInitialize()` i pętlę główną `mainLoop()`, by spełnić poniższe wymagania.

1. Po uruchomieniu dioda `D2` powinna być zgaszona.
1. Dioda `D2` powinna zaświecać się po wciśnięciu przycisku `A1` i gasnąć po jego puszczeniu.

\awesomebox[violet]{2pt}{\faBook}{violet}{Zapoznaj się z rejestrami \lstinline{PORT} (\textit{Data Register}) i~\lstinline{PIN} (\textit{Input Pins Address}), które pozwalają, odpowiednio, zapisywać stan wyjściowy i odczytywać stan wejściowy z danego portu.}

\awesomebox[teal]{2pt}{\faCode}{teal}{Możesz użyć makra \lstinline{bit_is_clear()} do sprawdzenia, czy pin wejściowy jest w~stanie~\lstinline{0}.}

# Zadanie rozszerzone

## Wymagania funkcjonalne

Zmodyfikuj pętlę główną \lstinline{mainLoop()}, by spełnić poniższe wymagania.

1. Po uruchomieniu diody `D2`…`D4` powinny być zgaszone.
1. Każda z diod powinna zaświecać się po wciśnięciu przypisanego jej przycisku (np. `A1` dla diody `D2`) i gasnąć po jego puszczeniu.
1. Wciśnięcie kilku przycisków jednocześnie powinno zaświecać odpowiednie diody.

\awesomebox[violet]{2pt}{\faBook}{violet}{Z dokumentacji płytki \textit{WPSH209} i \textit{Arduino Uno} odczytaj numerację pinów, do których podłączone są diody i przyciski.}

\awesomebox[teal]{2pt}{\faCode}{teal}{Możesz użyć operatora przesunięcia bitowego \lstinline{>>}, aby ominąć kłopotliwą różnicę w~numeracji pinów dla przycisków i LED-ów.}
