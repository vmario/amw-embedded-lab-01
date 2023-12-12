---
title: "Ćwiczenie 1: Odczyt i zapis GPIO"
author: [Mariusz Chilmon <<mariusz.chilmon@ctm.gdynia.pl>>]
lang: "pl"
titlepage: no
colorlinks: yes
header-right: "\\faEdit"
footer-left: "Sprawozdanie z laboratorium"
header-includes: |
  \usepackage{awesomebox}
...

_W trosce o Państwa wyniki proszę o czytelne wpisywanie nazwisk._

**Data**: \dotfill

**Autorzy**: \dotfill

# Część praktyczna

## Zadanie podstawowe

**Ocena prowadzącego**: \dotfill

## Zadanie rozszerzone

**Ocena prowadzącego**: \dotfill

# Część teoretyczna

## Zadanie podstawowe

Opisz przeznaczenie rejestrów `DDR`, `PIN` i `PORT`. Zwróć uwagę na znaczenie rejestrów `PORT` w&nbsp;zależności od kierunku portu.

`DDR` --- 
\vspace{1.5cm}

`PIN` --- 
\vspace{1.5cm}

`PORT` w przypadku pinu wejściowego --- 
\vspace{1.5cm}

`PORT` w przypadku pinu wyjściowego --- 
\vspace{1.5cm}

## Zadanie rozszerzone

![Kod źródłowy w języku C++ i efekt kompilacji w serwisie _godbolt.org_](port.png)

Podaj efekt kompilacji instrukcji zapisu stanu portu `PORTB = 0b00001000`, ustawienia pojedynczego bitu `PORTB |= 0b00001000` i ustawienia wielu bitów `PORTB |= 0b00101000`. Opisz instrukcje, które zastosował kompilator:

`PORTB  = 0b00001000` $\longrightarrow$
\vspace{1.5cm}

`PORTB |= 0b00001000` $\longrightarrow$
\vspace{1.5cm}

`PORTB |= 0b00101000` $\longrightarrow$
\vspace{1.5cm}

\awesomebox[teal]{2pt}{\faCode}{teal}{Zwróć uwagę, że w językach C i C++ operator przypisania \lstinline{=} jest na ogół prostszy niż operator przypisania złożonego z alternatywą bitową \lstinline{|=}, który standardowo wymaga odczytania zmiennej, wykonania operacji \lstinline{|} i zapisania wyniku do tej zmiennej. Tu jednak możliwe jest wykorzystanie dedykowanej instrukcji, o ile ustawiamy pojedynczy bit.}
