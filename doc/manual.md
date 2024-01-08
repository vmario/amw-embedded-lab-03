---
title: "Ćwiczenie 3: Regulacja jasności LED za pomocą timera"
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

> Fortune favors the prepared mind.
>
> — _Louis Pasteur_

# Cel ćwiczenia

Celem ćwiczenia jest zapoznanie się z:

* regulacją za pomocą modulacji szerokości impulsu,
* wykorzystaniem timera jako źródła sygnału PWM,
* odmierzaniem czasu za pomocą timera.

# Uruchomienie programu wyjściowego

1. Podłącz płytkę _WPSH209_ do _Arduino Uno_.
1. Zweryfikuj, czy dioda `D1` świeci maksymalną jasnością.
1. Zweryfikuj, czy dioda `D3` mruga słabym światłem.

Dioda `D3` podłączona jest do pinu `PB3`, którego alternatywną funkcją jest `OC2A` (_Timer/Counter2 Output Compare Match A Output_), co oznacza, że jest sterowany zdarzeniem generewanym przez kanał&nbsp;_A_ peryferiału _Timer/Counter2_. Timer ten został skonfigurowany w trybie _Fast PWM_. Jest to tryb, w&nbsp;którym możliwe jest regulowanie mocy dostarczanej do urządzenia wyjściowego (np. LED) poprzez szybkie włączanie i&nbsp;wyłączanie zasilania. Zmieniając proporcję między czasem włączenia i wyłączenia możemy dostarczyć mniej lub więcej mocy w jednostce czasu. W naszym przypadku wpływa to na jasność diody `D3`.

![Regulacja mocy za pomocą modulacji szerokości impulsu](pwm.svg)

Licznik `TCNT` (_Timer/Counter Register_) timera w trybie _Fast PWM_ zmienia się od wartości `BOTTOM` (`0x00`) do wartości `TOP` (`0xFF`). Przy wartości `0x00` wyjście `OC2A` załącza sterowane urządzenie, a&nbsp;przy zrównaniu licznika z&nbsp;zaprogramowaną wartością `OCR2A` (_Output Compare Register A_) — wyłącza je. Wartość wpisana do rejestru `OCR2A` pozwala zatem wprost regulować moc dostarczaną do sterowanego urządzenia bez angażowania CPU.

![Licznik pracujący w trybie _Fast PWM_](pwm-fast.png)

\awesomebox[purple]{2pt}{\faMicrochip}{purple}{\textit{Timer/Counter2} może generować dwa sygnały na wyjściach \lstinline{OC2A} i \lstinline{OC2B}, sterowanych — odpowiednio — wartościami rejestrów \lstinline{OCR2A} i \lstinline{OCR2B}. W~tym zadaniu korzystamy tylko z kanału \textit{A} — wyjścia \lstinline{OC2A} i sterującego nim rejestru \lstinline{OCR2A}.}

\awesomebox[purple]{2pt}{\faMicrochip}{purple}{Mikrokontrolery AVR obok trybut \textit{Fast PWM} udostępniają także tryb \textit{Phase Correct PWM}, w którym uzyskiwana częstotliwość sygnału jest mniejsza, ale sposób synchronizacji impulsów jest korzystniejszy dla sterowania silników.}

# Zadanie podstawowe

## Wymagania funkcjonalne

1. Dioda `D1` świeci maksymalną jasnością.
1. Dioda `D3` świeci połową jasności bez zauważalnego mrugania. Jasność oceń organoleptycznie[^1].

## Modyfikacja programu

Zmodyfikuj funkcję `pwmInitialize()`:

1. Mruganie diody jest zauważalne, ponieważ timer taktowany jest zbyt wolnym zegarem. Zapoznaj się z bitami `CS20`…`CS22`.
1. Użyj rejestru `OCR2A`, by ustawić jasność diody.

![Za pomocą bitów `CS20`…`CS22` wybierany jest odpowiednio podzielony zegar](timer-prescaler.png)

\awesomebox[violet]{2pt}{\faBook}{violet}{Potrzebne informacje znajdziesz w rozdziale \textit{8-bit Timer/Counter2 with PWM and Asynchronous Operation}, w szczególności w sekcji \textit{Register Description} dokumentacji mikrokontrolera.}

\awesomebox[purple]{2pt}{\faMicrochip}{purple}{W tym ćwiczeniu mikrokontroler taktowany jest zegarem $clk_{I/O} = 2~\text{MHz}$.}

# Zadanie rozszerzone

## Wymagania funkcjonalne

1. Dioda `D1` świeci maksymalną jasnością.
1. Jasność diody `D3` cyklicznie i płynnie zmienia się od minimalnej do maksymalnej i z powrotem.

## Modyfikacja programu

Wykorzystaj przerwanie `TIMER2_OVF` (plik `pwm.cpp`), które wywoływane jest po przepełnieniu timera (na koniec każdego cyklu odliczania).

\awesomebox[purple]{2pt}{\faMicrochip}{purple}{Przerwanie włącza flaga \lstinline{TOIE2} oraz funkcja \lstinline{sei()}.}

[^1]: Innymi słowy &bdquo;na oko&rdquo;.
