# ------------------
#     Mappings
# ------------------

# C-b is not acceptable -- Vim uses it
set-option -g prefix C-b
#bind-key C-a last-window
bind-key C-b last-window

# Allows us to use C-a a <command> to send commands to a TMUX session inside 
# another TMUX session
bind-key a send-prefix

# set window split
bind-key v split-window -h
bind-key b split-window

# hjkl pane traversal
bind h select-pane -L
bind j select-pane -D
bind k select-pane -U
bind l select-pane -R

bind-key -n C-j resize-pane -D 2
bind-key -n C-k resize-pane -U 2

bind c command-prompt -p "Name of new window: " "new-window -n '%%'"

# reload config
bind r source-file ~/.tmux.conf \; display-message "Config reloaded..."

# ------------------
#    Settings 
# ------------------

# default shell
# Check the system and set the default shell accordingly
if-shell "uname | grep -q 'Darwin'" "set-option -g default-shell /opt/homebrew/bin/fish"
if-shell "uname | grep -q 'Linux'" "set-option -g default-shell /usr/bin/fish"

# auto window rename
set-window-option -g automatic-rename

# Activity monitoring
setw -g monitor-activity on
set -g visual-activity on

# Start numbering at 1
set -g base-index 1

# Allows for faster key repetition
set -s escape-time 50

# Rather than constraining window size to the maximum size of any client 
# connected to the *session*, constrain window size to the maximum size of any 
# client connected to *that window*. Much more reasonable.
setw -g aggressive-resize on

# Vi copypaste mode
set-window-option -g mode-keys vi
if-shell "test '\( #{$TMUX_VERSION_MAJOR} -eq 2 -a #{$TMUX_VERSION_MINOR} -ge 4 \)'" 'bind-key -Tcopy-mode-vi v send -X begin-selection; bind-key -Tcopy-mode-vi y send -X copy-selection-and-cancel'
if-shell '\( #{$TMUX_VERSION_MAJOR} -eq 2 -a #{$TMUX_VERSION_MINOR} -lt 4\) -o #{$TMUX_VERSION_MAJOR} -le 1' 'bind-key -t vi-copy v begin-selection; bind-key -t vi-copy y copy-selection'

set-option -g mouse off


# ------------------
#     Color 
# ------------------

# https://github.com/seebi/tmux-colors-solarized/blob/master/tmuxcolors-256.conf
set-option -g status-style bg=colour235,fg=colour136,default # bg=base02, fg=yellow

# default window title colors
set-window-option -g window-status-style fg=colour244,bg=default,dim # fg=base0
# active window title colors
set-window-option -g window-status-current-style fg=colour0,bg=default # fg=black

# pane border
set-option -g pane-border-style fg=colour235 #fg=base02
set-option -g pane-active-border-style fg=colour240 #fg=base01


# message text
set-option -g message-style bg=colour235,fg=colour166 # bg=base02, fg=orange

set -g status-interval 1
set -g status-justify centre # center align window list
set -g status-left-length 24
set -g status-right-length 140

# Try xterm256-color (https://github.com/tmux/tmux/issues/622):
if-shell "test '\( #{$TMUX_VERSION_MAJOR} -eq 2 -a #{$TMUX_VERSION_MINOR} -ge 6
\)'" 'set -g default-terminal "screen-256color"'
if-shell "test '\( #{$TMUX_VERSION_MAJOR} -eq 2 -a #{$TMUX_VERSION_MINOR} -ge 6
\)'" 'set -ga terminal-overrides ",screen-256color:Tc"'
