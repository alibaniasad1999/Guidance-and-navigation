import os
from PIL import Image
import re

# make function key for sort by number
def key_func(x):
    return [int(c) if c.isdigit() else c for c in re.split('([0-9]+)', x)]


def create_gif(image_list, gif_name, duration=0.01):
    frames = []
    for image_name in image_list:
        # delete pixels near white color and convert to RGBA
        img = Image.open(image_name).convert('RGBA')
        pixdata = img.load()
        width, height = img.size
        for y in range(height):
            for x in range(width):
                # delete bright pixels with lower threshhold
                if pixdata[x, y][0] > 100 and pixdata[x, y][1] > 100 and pixdata[x, y][2] > 100:
                    pixdata[x, y] = (255, 255, 255, 0)
        frames.append(img)

    # Save gif, each frame shown individually without combining
    frames[0].save(
        gif_name,
        format='GIF',
        append_images=frames[1:],
        save_all=True,
        duration=duration,
        loop=0,
        transparency=0,  # Set transparency to 0 to avoid combining frames
        disposal=2  # Set disposal to 2 for proper frame rendering
    )


def main():
    # All PNG images in the specified directory
    couter = 0
    dir = 'Figure/MIL/time_line/'
    image_list = []
    image_name_list = os.listdir(dir)
    # Sort by name number
    image_name_list.sort(key=key_func)
    for filename in image_name_list:
        if filename.endswith('.png'):
            image_list.append(os.path.join(dir, filename))
    gif_name = os.path.join(dir, 'created_dayan.gif')
    duration = 100  # Adjust the duration (in milliseconds) as needed
    create_gif(image_list, gif_name, duration)


if __name__ == '__main__':
    main()
