# Extension testing

1. Convert image to binary format using [image_conversion.py](./util/image_conversion.py): `python util/image_conversion.py images/foreman.png images/foreman.bin` (requires PIL and numpy packages)
2. Compile test CPP program in [example_cpp_program](./example_cpp_program/)
3. In extension testing instance, set break point and start debugging the CPP program