/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:15:16 by egomez-a          #+#    #+#             */
/*   Updated: 2021/12/17 16:25:09 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int ft_close ()
{
	exit(0);
}

/* Any functon that you hook with the key event must be like this:
* Recibing and int for the code of the key pressed
* and a void pointer in case you need to recibe someting */
// int	ft_input(int key, void *param)
// {
// 	t_program *program = (t_program *)param;

// 	// mlx function that clears the window
// 	mlx_clear_window(program->mlx, program->window.reference);

// 	// move in a direction based on the key
// 	if (key == 124)
// 		program->sprite_position.x += program->sprite.size.x;
// 	else if (key == 123)
// 		program->sprite_position.x -= program->sprite.size.x;
// 	else if (key == 125)
// 		program->sprite_position.y += program->sprite.size.y;
// 	else if (key == 126)
// 		program->sprite_position.y -= program->sprite.size.y;
// 	// change color based on keys R, G and B.
// 	else if (key == 15)
// 		turn_img_to_color(&program->sprite, new_color(255,0,0,0));
// 	else if (key == 5)
// 		turn_img_to_color(&program->sprite, new_color(0,255,0,0));
// 	else if (key == 11)
// 		turn_img_to_color(&program->sprite, new_color(0,0,255,0));

// 	// mlx function that puts and image into a window at a given position
// 	// (the position 0,0 is the upper-left corner)
// 	mlx_put_image_to_window(program->mlx, program->window.reference,
// 		program->sprite.reference, program->sprite_position.x, program->sprite_position.y);

// 	// print the key pressed so you know the number of each key
// 	printf("Key pressed -> %d\n", key);
// 	return (0);
// }

int	ft_update (void *param)
{
	t_program	*program = (t_program *)param;
	// a static that saves how many frames have passed
	static int	frame;

	// add a frame and every x frames change the position by 1 pixel
	// so it looks like its animated
	frame++;
	if (frame == ANIMATION_FRAMES)
		program->sprite_position.y += 1;
	// every x*2 frames go back that pixel to loop the animation
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		program->sprite_position.y -= 1;
		frame = 0;
	}
	
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->sprite_position.x, program->sprite_position.y);

	return (0);
}

t_window	ft_new_window(void *mlx, int widht, int height, char *name)
{
	t_window	window;

	/* This mlx function creates a returns a pointer
	to a new window with a given size and name */
	window.reference = mlx_new_window(mlx, widht, height, name);
	printf("puntero creacion window es %p\n", window.reference);
	window.size.x = widht;
	window.size.y = height;

	// Now we 'hook' the function ft_close() to the closing window event
	mlx_hook(window.reference, 17, 0, ft_close, 0);

	return (window);
}

/* Returns an image of <width> x <height> black pixels. */
t_image ft_new_image(void* mlx, int width, int height)
{
	t_image img;

	/* mlx function that creates and returns a pointer
	to an image of the given width and height */
	img.reference = mlx_new_image(mlx, width, height);
	img.size.x = width;
	img.size.x = height;

	/* mlx function that returs a pointer to the first pixel of the given image.
	* ¡Pixels are not stored in a 2D table, just a single char[] array!
	* the fuction also saves in the given pointers:
	*	the bits per pixel (each pixel is usually 4 chars of the array),
	* 	the line size of the pixels array  (the amount of pixels in one line of the image)
	* 	and the endian (info of how the colors are stored) */
	img.pixels = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_size, &img.endian);

	return (img);
}

/* Returns an image with the sprite found in <path> */
t_image ft_new_sprite(void *mlx, char *path)
{
	t_image img;
	
	/* mlx function that creates and image that contains the xmp file found in the given path.
	* It also saves the width and height of the image in the pointers passed as parameters */
	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

void	open_window(t_map map)
{
	t_program	program;

	program.mlx = mlx_init();
	printf("Creado el puntero mlx\n");
	program.window = ft_new_window(program.mlx, map.lines * 32, map.cols * 32, "Bienvenido al juego de so_long!");
	// Create a new image/sprite (image.c)
	program.sprite = ft_new_sprite(program.mlx, "images/wall.xpm");
	printf("creada imagen\n");
	program.sprite_position.x = 0;
	program.sprite_position.y = 0;
			// mlx function that draws an image into a window at the given position
	while (program.sprite_position.x < map.cols * 32 - 32)
	{
		mlx_put_image_to_window(program.mlx, program.window.reference,
			program.sprite.reference, program.sprite_position.x, program.sprite_position.y);
		program.sprite_position.x += 32;
	}
	// hook the input() (hooks.c) function to the the key pressed event
	// mlx_key_hook(program.window.reference, *ft_input, &program);
	// hook a function to the loop (it would be called each frame)
	// mlx_loop_hook(program.mlx, *ft_update, &program);
	mlx_loop(program.mlx);
}

int	main(int argc, char **argv)
{
	t_map		map;

	map.lines = 0;
	if (argc == 2)
	{
		check_map_extension(argv[1]);
		map = read_map(argv[1]);
		open_window(map);
	}
	else
		ft_putstr_fd("Error. Wrong number of arguments.\n", 2);
	return (0);
}