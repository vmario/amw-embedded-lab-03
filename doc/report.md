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

Zaznacz bity, które należy ustawić, by włączyć przerwania od zmiany pinów `PB1`, `PB2` i `PD5`.

\begin{tikzpicture}[node distance=0mm,
box/.style={draw, minimum height=7mm, minimum width=18mm},
label/.style={font=\bfseries, minimum height=7mm, minimum width=18mm},
value/.style={font=\small, yshift=7mm},
]
\node[box] (b7)               {---};
\node[box] (b6) [right=of b7] {---};
\node[box] (b5) [right=of b6] {---};
\node[box] (b4) [right=of b5] {---};
\node[box] (b3) [right=of b4] {---};
\node[box] (b2) [right=of b3] {PCIE2};
\node[box] (b1) [right=of b2] {PCIE1};
\node[box] (b0) [right=of b1] {PCIE0};
\node[label] [right=of b0] {PCICR};
\node[value] [above of=b7] {7};
\node[value] [above of=b6] {6};
\node[value] [above of=b5] {5};
\node[value] [above of=b4] {4};
\node[value] [above of=b3] {3};
\node[value] [above of=b2] {2};
\node[value] [above of=b1] {1};
\node[value] [above of=b0] {0};
\end{tikzpicture}

\begin{tikzpicture}[node distance=0mm,
box/.style={draw, minimum height=7mm, minimum width=18mm},
label/.style={font=\bfseries, minimum height=7mm, minimum width=18mm},
]
\node[box] (b7)               {PCINT23};
\node[box] (b6) [right=of b7] {PCINT22};
\node[box] (b5) [right=of b6] {PCINT21};
\node[box] (b4) [right=of b5] {PCINT20};
\node[box] (b3) [right=of b4] {PCINT19};
\node[box] (b2) [right=of b3] {PCINT18};
\node[box] (b1) [right=of b2] {PCINT17};
\node[box] (b0) [right=of b1] {PCINT16};
\node[label] [right=of b0] {PCMSK2};
\end{tikzpicture}

\begin{tikzpicture}[node distance=0mm,
box/.style={draw, minimum height=7mm, minimum width=18mm},
label/.style={font=\bfseries, minimum height=7mm, minimum width=18mm},
]
\node[box] (b7)               {---};
\node[box] (b6) [right=of b7] {PCINT14};
\node[box] (b5) [right=of b6] {PCINT13};
\node[box] (b4) [right=of b5] {PCINT12};
\node[box] (b3) [right=of b4] {PCINT11};
\node[box] (b2) [right=of b3] {PCINT10};
\node[box] (b1) [right=of b2] {PCINT9};
\node[box] (b0) [right=of b1] {PCINT8};
\node[label] [right=of b0] {PCMSK1};
\end{tikzpicture}

\begin{tikzpicture}[node distance=0mm,
box/.style={draw, minimum height=7mm, minimum width=18mm},
label/.style={font=\bfseries, minimum height=7mm, minimum width=18mm},
]
\node[box] (b7)               {PCINT7};
\node[box] (b6) [right=of b7] {PCINT6};
\node[box] (b5) [right=of b6] {PCINT5};
\node[box] (b4) [right=of b5] {PCINT4};
\node[box] (b3) [right=of b4] {PCINT3};
\node[box] (b2) [right=of b3] {PCINT2};
\node[box] (b1) [right=of b2] {PCINT1};
\node[box] (b0) [right=of b1] {PCINT0};
\node[label] [right=of b0] {PCMSK0};
\end{tikzpicture}

\begin{tikzpicture}[node distance=0mm,
box/.style={draw, minimum height=7mm, minimum width=18mm},
label/.style={font=\bfseries, minimum height=7mm, minimum width=18mm},
]
\node[box] (b7)               {I};
\node[box] (b6) [right=of b7] {T};
\node[box] (b5) [right=of b6] {H};
\node[box] (b4) [right=of b5] {S};
\node[box] (b3) [right=of b4] {V};
\node[box] (b2) [right=of b3] {N};
\node[box] (b1) [right=of b2] {Z};
\node[box] (b0) [right=of b1] {C};
\node[label] [right=of b0] {SREG};
\end{tikzpicture}

Jaką komendą ustawisz bit w rejestrze statusu `SREG`, a jaką go wyzerujesz?
\vspace{1.5cm}

## Zadanie rozszerzone

Zarówno pin `PB1`, jak i `PB2` obsługiwane są przez przerwanie `PCI0`. Jak odróżnić, który z pinów wywołał przerwanie?
\vspace{1.5cm}

Kiedy nie będziemy w stanie poprawnie ocenić źródła tego przerwania?
\vspace{1.5cm}

