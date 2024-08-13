# Finding Qt signal/slot cycles

[QtSignals.py](../bin/Examples/QtSignals.py) analyzes signal/slot connections in a Qt codebase, visualizes them as
a DOT digraph, and allows one to isolate the strongly connected components, i.e.
the cycles in signals/slots relations.
