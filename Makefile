all: src/protobuf anmeldung

anmeldung: src/protobuf
	${CC} ./src/anmeldung.c -o anmeldung

clean:
rm -rf ./anmeldung
