JAVAC=javac
JAVA=java
MAIN=TestClass1
sources = $(wildcard *.java)
classes = $(sources:.java=.class)

all: myProgram

myProgram: $(classes)

%.class: %.java
	$(JAVAC) $<

clean:
	rm -f *.class
	rm -f *.txt