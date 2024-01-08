---
title: "Ćwiczenie 3: Regulacja jasności LED za pomocą timera"
author: [Mariusz Chilmon <<mariusz.chilmon@ctm.gdynia.pl>>]
lang: "pl"
titlepage: no
colorlinks: yes
header-right: "\\faEdit"
footer-left: "Sprawozdanie z laboratorium"
header-includes: |
  \usepackage{awesomebox}
  \usepackage{tikz}
  \usetikzlibrary{positioning}
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

Z jaką rozdzielczością można ustalić wypełnienie przebiegu PWM sterującego jasnością LED?
\vspace{2.0cm}

Przy jakiej częstotliwości PWM mruganie LED stało się niezauważalne?
\vspace{2.0cm}

\awesomebox[violet]{2pt}{\faBook}{violet}{Potrzebne informacje znajdziesz w rozdziale \textit{8-bit Timer/Counter2 with PWM and Asynchronous Operation}, w szczególności w sekcji \textit{Fast PWM Mode} dokumentacji mikrokontrolera.}

## Zadanie rozszerzone

Co robi funkcja `holdYourHorses()`?
\vspace{1.5cm}

Z jaką częstotliwością mrugałaby dioda D3 w programie wyjściowym, gdyby ta funkcja była wyłączona?
\vspace{1.5cm}

## \faCertificate&nbsp; Zadanie specjalne

_+1 pkt dla osoby, która jako pierwsza poda poprawną odpowiedź._

Dlaczego połowę jasności diody uzyskuje się znacznie poniżej wartości połowy zakresu nastaw PWM, a&nbsp;więc poniżej $\frac{2^8}{2} - 1 = 127$?
