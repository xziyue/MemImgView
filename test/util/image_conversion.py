# convert images to a format that can be easily read by C++ program
# usage: python convert_images.py input_directory output_file

from PIL import Image
import sys
import os
import struct

input_path = sys.argv[1]
output_path = sys.argv[2]

if not os.path.exists(input_path):
    print(f"Input directory '{input_path}' does not exist.")
    sys.exit(1)

# open input image
img = Image.open(input_path)

# convert to 8 bit grayscale
img = img.convert('L')

# write to output
with open(output_path, 'wb') as f:
    # write width and height
    f.write(struct.pack('I', img.width))
    f.write(struct.pack('I', img.height))
    
    # write pixel data
    for row in img.getdata():
        f.write(struct.pack('B', row))


print(f"Image converted and saved to {output_path}")

