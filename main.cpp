#include "raylib.h"
#include <string>

int max_files_music;


FilePathList music_names = LoadDirectoryFiles("music");

Music muzika;

int selected_music = -1;


float full_song_time;


bool is_name_ready;

bool music_directory_exists;

bool files;

bool debug = false; // change to true to debug 

bool is_play_button_pressed;

bool music_is_selected;

bool muzikata_e_pusnata;

bool molq_pusni_se;

FilePathList music_files;

void directory_check()
{
    DirectoryExists("music");
    if(DirectoryExists("music"))
    {
        music_directory_exists = true;
    }
    
    if(!DirectoryExists("music"))
    {
        MakeDirectory("music");
        directory_check();
    }
}

void get_music_files()
{
    //FilePathList LoadDirectoryFilesEx(const char *basePath, const char *filter, bool scanSubdirs);
    music_files = LoadDirectoryFilesEx("music", ".mp3", false);
    if(music_files.count > 0)
    {
        files = true;
    }
}

int max_files = music_files.count;







int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    //const int screenWidth = 3440;
    //const int screenHeight = 1440;
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    InitWindow(screenWidth, screenHeight, "Media player");//TODO: invent a name
    //MaximizeWindow();
    
    
    //AUDIO INITIALIZATION
    InitAudioDevice();
    
    
    
    
    
    //DIRECTORY CHECK
    directory_check();
    
    
    
    //GET MUSIC FILES
    get_music_files();
    
    
    music_names = LoadDirectoryFiles("music");
    is_name_ready = true;
    
    


    SetTargetFPS(165);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        
        Vector2 mishka = GetMousePosition();
        
        
        Rectangle get_sound ;
        
        
        
        
        

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);
            DrawText("MUSIC PLAYER", 1500, 100, 20, WHITE);
            DrawText("CLICK YOUR FAVOURITE MUSIC TO START PLAYING IT <3", 300, 200, 20, WHITE);
            
            
            DrawRectangle(1400, 200, 600, 700, GRAY);
            
            
            
            
            
            if (debug == true)
            {
            if(music_directory_exists == true) 
            {
                DrawText("MUSIC DIRECTORY EXISTS", 190, 200, 20, WHITE);
            } 
            if(music_directory_exists == false)
            {
                MakeDirectory("music");
                DrawText("MUSIC DIRECTORY IS MADE NOW . REBOOT TO REMOVE THIS MESSAGE", 190, 250, 20, WHITE);
            }
            if(is_name_ready == true)    
            {
                DrawText("NAMES CAN BE GETTED", 190, 300, 20, WHITE);
            } 

            if (files == true)
            {
                for(int i = 0; i <= max_files ; i++)
                {
                    DrawText(TextFormat("Files: %i", music_files.count), 190, 250, 20, WHITE);
                    //DrawText(TextFormat("Files: %i", files_names),1400, 200, 20, RED);
                }
            }             
            }
            
            
            if(is_name_ready == true)
            {
                for(int i = 0; i < music_files.count; i++)
                {
                    Rectangle get_sound = { 1400, 200 + (i * 15), 600, 20 };
                    DrawRectangleRec(get_sound, BLANK);
                    DrawText(music_files.paths[i], 1400, 200 + (i * 20), 20, WHITE);
                    //DrawRectangle(1400, 200 + (i * 20), 600, 20, BLANK);
                    if(CheckCollisionPointRec(mishka, get_sound))
                    {
                        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                        {

                            selected_music = i;
                            muzika = LoadMusicStream(music_files.paths[selected_music]);
                            PlayMusicStream(muzika);
                            music_is_selected = true;
                            muzikata_e_pusnata = true;
                            GetMusicTimeLength(muzika);
                            molq_pusni_se = false;
                            
                        }
                    }
                }
                
            }
            
            if (music_is_selected)
            {
                UpdateMusicStream(muzika);
            }
            
            
            if(muzikata_e_pusnata == true)
            {
                if(IsMusicStreamPlaying(muzika))
                {
                    //DrawText("Playing...", 190, 250, 20, WHITE); 
                    
                    muzikata_e_pusnata = false;
                    molq_pusni_se = true;
                }
            }
            
            if(molq_pusni_se == true)
            {
                DrawText(music_files.paths[selected_music],190, 250, 20, WHITE );
            }
            
            
            
            DrawText(TextFormat("Playing for: %f" , GetMusicTimePlayed(muzika)),190, 350, 20, WHITE );
            DrawText(TextFormat("Full time of the music: %f" , GetMusicTimeLength(muzika)),190, 400, 20, WHITE );
            
            full_song_time = GetMusicTimeLength(muzika);
            if(GetMusicTimePlayed(muzika) >= full_song_time)
            {
                molq_pusni_se = false;
                DrawText(music_files.paths[selected_music],190, 250, 20, WHITE );
            }
            
            
            
            
            
            
            
            
            
            
            
            
            
            if(IsKeyPressed(KEY_LEFT_ALT) && IsKeyPressed(KEY_TAB)) //TODO: make full screen and when alt + tab to minimize
            {    
                MinimizeWindow();               
            }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    
    //CLOSE AUDIO DEVICES
    CloseAudioDevice();
    
    UnloadMusicStream(muzika);
    
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}