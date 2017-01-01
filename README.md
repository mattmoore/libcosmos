# libcosmos

What is libcosmos?

libcosmos is a shared library that functions as a database administration tool and change management program for PostgreSQL.

libcosmos provides the ability handle database administration tasks.

libcosmos also provides system-independent migrations. It can take a database schema file and create the necessary SQL statements to create a database. It will also be able to determine what database objects are missing from a target database, and generate the necessary SQL to create any missing objects in the target database. There will be a force and non-destructive mode. The non-destructive mode will only create objects if they do not already exist. The force mode will attempt to generate SQL that will not damage existing data, yet it will actually attempt to non-destructively morph existing matching objects to match the schema definition.

## Build Instructions:

This project uses a GNU Makefile and should compile with Clang on Linux. It should also build on Mac OS X Yosemite/El Capitan with Clang.

1. Run "make clean" to verify a clean build.
1. Run "make" to build.
