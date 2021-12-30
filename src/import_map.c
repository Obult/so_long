/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   import_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: oswin <oswin@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/22 20:32:41 by oswin         #+#    #+#                 */
/*   Updated: 2021/12/22 21:59:45 by oswin         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	import_map(t_data *data, int argc, char **argv)
{
	if (argc != 2)
		return (-1);
	// import map stuff

	// ifnot()
	// 	return (-1)

	return (setup_mlx(data));
}