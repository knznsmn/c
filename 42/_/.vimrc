let g:auth = 'knznsmn'

function! Stdheader()
	let filename = expand('%:t')
	let width = 51 "desired width for variables  
	let filename_field = repeat(' ', width - strlen(filename))
	let au_fld = repeat(' ', width - 23 - strlen(g:auth))
	let date_fld = repeat(' ', width - 34 - strlen(g:auth))
	let st_t = strftime("%Y/%m/%d %H:%M:%S")

	let header  = "/* ****************************************************************************/\n"
	let header .= "/*                                                                            */\n"
	let header .= "/*                                                        :::      ::::::::   */\n"
	let header .= "/*   " . filename . filename_field .                   ":+:      :+:    :+:   */\n"
	let header .= "/*                                                    +:+ +:+         +:+     */\n"
	let header .= "/*   By: " . g:auth . " <mail@knznsmn>" . au_fld      ."+#+  +:+       +#+        */\n"
	let header .= "/*                                                +#+#+#+#+#+   +#+           */\n"
	let header .= "/*   Created: " . st_t . " by " . g:auth . date_fld ." #+#    #+#             */\n"
	let header .= "/*   Updated: " . st_t . " by " . g:auth . date_fld ."###   ########.kn       */\n"
	let header .= "/*                                                                            */\n"
	let header .= "/* ************************************************************************** */\n"

	call setline(1, header . getline(1))
	%s/\%x00/\r/g
endfunction

" Set <F1> as leader key
let mapleader = "\<F1>"

" Map <leader> to generate 42 header
nnoremap <leader> :call Stdheader()<CR>

" Map :Stdheader to generate 42 header
command! Stdheader call Stdheader()

function! UpdateHeader()
    let filename = expand('%:t')
    let width = 51 "desired width for variables
    let filename_field = repeat(' ', width - strlen(filename))
    let au_fld = repeat(' ', width - 23 - strlen(g:auth))
    let date_fld = repeat(' ', width - 34 - strlen(g:auth))
    let md_t = strftime("%Y/%m/%d %H:%M:%S")

    " check if the header exists
    let line1 = getline(1)
    if line1 != "/* ************************************************************************** */"
        return
    endif
    let line2 = getline(2)
    if line2 != "/*                                                                            */"
        return
    endif
    let line3 = getline(3)
    if line3 != "/*                                                        :::      ::::::::   */"
        return
    endif

    " update the timestamp on line 9
    let line9 = getline(9)
    if match(line9, 'Updated: \d\d\d\d/\d\d/\d\d \d\d:\d\d:\d\d by ' . g:auth . '.*') == -1
        echo "Timestamp not found"
        return
    endif
    let line9 = substitute(line9, 'Updated: \d\d\d\d/\d\d/\d\d \d\d:\d\d:\d\d', 'Updated: ' . md_t, '')
    call setline(9, line9)
endfunction

" automatically update the header on save
autocmd BufWritePre * call UpdateHeader()


" Appearance
set number                  " Show absolute line numbers
set relativenumber          " Show relative line numbers
syntax on                   " Enable syntax highlighting
set cursorline              " Highlight current line
set showmatch               " Highlight matching parentheses
set colorcolumn=80          " Highlight the 80th column
set wrap                    " Enable line wrapping
set linebreak               " Break lines at word boundaries
set scrolloff=8             " Keep 8 lines visible above/below cursor
set signcolumn=yes          " Always show the sign column

" Colorscheme 
colorscheme desert          " Built-in nice scheme, or try 'gruvbox', 'onedark', etc.

" Indentation
set tabstop=2               " Number of spaces that a <Tab> in the file counts for
set shiftwidth=2            " Number of spaces to use for each step of (auto)indent
set expandtab               " Use spaces instead of tabs
set autoindent              " Copy indent from current line when starting a new line
set smartindent             " Automatically insert indent in some cases

