% -----------------------------
% FACTS (Parent Relationships)
% -----------------------------
parent(pandu, arjuna).
parent(pandu, bheem).
parent(pandu, yudhishthira).

parent(kunti, arjuna).
parent(kunti, bheem).
parent(kunti, yudhishthira).

parent(dhritarashtra, duryodhana).
parent(gandhari, duryodhana).

% Guru–Disciple
guru(dronacharya, arjuna).
guru(dronacharya, bheem).
guru(dronacharya, duryodhana).


% -----------------------------
% RULES
% -----------------------------

% Brother: same parent (and not same person)
brother(X, Y) :-
    parent(P, X),
    parent(P, Y),
    X \= Y.

% Cousin: their parents are siblings
cousin(X, Y) :-
    parent(P1, X),
    parent(P2, Y),
    brother(P1, P2).

% Ancestor (Recursive rule)
ancestor(X, Y) :-
    parent(X, Y).

ancestor(X, Y) :-
    parent(X, Z),
    ancestor(Z, Y).

% Disciple (reverse of guru)
disciple(X, Y) :-
    guru(Y, X).