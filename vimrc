:colorscheme default 
:set tabstop=4
:set shiftwidth=4
nnoremap + :res +5<CR>
nnoremap _ :res -5<CR>
filetype indent on
syntax on
:set nu
inoremap " ""<left>
inoremap ' ''<left>
inoremap ( ()<left>
inoremap [ []<left>
inoremap { {}<left>
inoremap {<CR> {<CR>}<ESC>O
inoremap {;<CR> {<CR>};<ESC>O


