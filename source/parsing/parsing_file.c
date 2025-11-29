/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 09:08:01 by lmarion           #+#    #+#             */
/*   Updated: 2025/09/23 09:08:02 by lmarion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

unsigned char	file_read_type_sub(t_alloc *_alloc, t_file_obj *filedata)
{
	if (ft_isalpha(filedata->buffer) != 0)
	{
		if (filedata->lock == 1)
			return (1);
		if (filedata->buffer_size == CONFIG_MAX_LINESIZE)
			return (1);
		filedata->buffer_data[filedata->buffer_size] = filedata->buffer;
		filedata->buffer_size += 1;
	}
	else if (ft_isspace(filedata->buffer) != 0)
	{
		if (filedata->buffer == '\n')
		{
			try_get_type(_alloc, filedata->buffer_data,
				&filedata->buffer_size, &filedata->error);
			if (filedata->error == 1)
				return (1);
			filedata->lock = 0;
		}
	}
	else
		filedata->lock = 1;
	return (0);
}

unsigned char	file_read_type(int fd, t_alloc *_alloc)
{
	t_file_obj	filedata;

	if (fd < 0)
		error(ERROR_BAD_FILE);
	filedata.error = 0;
	filedata.lock = 0;
	ft_bzero(filedata.buffer_data, sizeof(filedata.buffer_data));
	filedata.buffer_size = 0;
	while (filedata.error == 0)
	{
		if (read(fd, &filedata.buffer, 1) == 0)
		{
			try_get_type(_alloc, filedata.buffer_data,
				&filedata.buffer_size, &filedata.error);
			break ;
		}
		else
		{
			if (file_read_type_sub(_alloc, &filedata) == 1)
				filedata.error = 1;
		}
	}
	close(fd);
	_alloc->index = 0;
	return (filedata.error);
}

unsigned char	file_read_value_subbis(t_alloc *_alloc, t_file_obj *filedata)
{
	if (filedata->lock == 1)
		filedata->lock = 0;
	if (filedata->lock == 0)
	{
		if (filedata->buffer == '\n')
		{
			try_get_value(_alloc, filedata->buffer_data, &filedata->buffer_size,
				&filedata->error);
			if (filedata->error == 1)
				return (1);
			filedata->lock = 2;
		}
		if (filedata->buffer_size != 0
			&& filedata->buffer_data[filedata->buffer_size - 1] != ' ')
		{
			if (filedata->buffer_size == CONFIG_MAX_LINESIZE)
				return (1);
			filedata->buffer_data[filedata->buffer_size] = ' ';
			filedata->buffer_size += 1;
		}
	}
	return (0);
}

unsigned char	file_read_value_sub(t_alloc *_alloc, t_file_obj *filedata)
{
	if (ft_isalpha(filedata->buffer) != 0)
		filedata->lock = 1;
	else if (ft_isspace(filedata->buffer) != 0)
	{
		if (file_read_value_subbis(_alloc, filedata) == 1)
			return (1);
	}
	else
	{
		if (filedata->lock != 0)
			return (1);
		if (filedata->buffer_size == CONFIG_MAX_LINESIZE)
			return (1);
		filedata->buffer_data[filedata->buffer_size] = filedata->buffer;
		filedata->buffer_size += 1;
	}
	return (0);
}

unsigned char	file_read_value(int fd, t_alloc *_alloc)
{
	t_file_obj	filedata;

	if (fd < 0)
		error(ERROR_BAD_FILE);
	filedata.error = 0;
	_alloc->index = 0;
	filedata.lock = 2;
	ft_bzero(filedata.buffer_data, sizeof(filedata.buffer_data));
	filedata.buffer_size = 0;
	while (filedata.error == 0)
	{
		if (read(fd, &filedata.buffer, 1) == 0)
		{
			try_get_value(_alloc, filedata.buffer_data,
				&filedata.buffer_size, &filedata.error);
			break ;
		}
		else
		{
			if (file_read_value_sub(_alloc, &filedata) == 1)
				filedata.error = 1;
		}
	}
	close(fd);
	return (filedata.error);
}
