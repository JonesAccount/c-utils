void clear_screen(void) {
    printf("\033[2J");  
    printf("\033[H");   
    fflush(stdout);     
}