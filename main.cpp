#include "raylib.h"
#include <string>

int max_files_music;


FilePathList music_names = LoadDirectoryFiles("music");

Music muzika;

int selected_music = -1;


float full_song_time;

bool enable_pause = false;

bool is_name_ready;

bool music_directory_exists;

bool files;

bool debug = false; // change to true to debug 

bool is_play_button_pressed;

bool music_is_selected;

bool muzikata_e_pusnata;

bool molq_pusni_se;

bool pause;

int volume_slide;

int sila_zvuk = 600;

float volume = 1.0f;

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
    //use ; to seperate different filters
    music_files = LoadDirectoryFilesEx("music", ".mp3;.ogg;.wav;", false);
    if(music_files.count > 0)
    {
        files = true;
    }
}

int max_files = music_files.count;

//TODO REFACTOR UI AND MAKE MORE RESPONSIVE VOLUME SLIDER
//TODO MAKE PORT FOR 1080p MONITORS




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
            
           
            
           
            for(int j = 0; j <= 100; j++)
            {
                DrawRectangle(1350 , 600 + (j + 1) , 20, 10 , WHITE);
            }
            
             
             
            //DrawCircle(1360, sila_zvuk, 20, GRAY); 
            
            if(CheckCollisionPointCircle(mishka, {1360 , sila_zvuk} , 20))
            {
                if(IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                {
                    //logic yoy
                    if(mishka.y > sila_zvuk)
                    {
                        sila_zvuk++;
                        volume -= 0.01f;
                    }
                    else if(mishka.y < sila_zvuk)
                    {
                        sila_zvuk--;
                        volume += 0.01f;
                    }
                    if(sila_zvuk <= 600)
                    {
                        sila_zvuk = 600;
                        
                    }
                    else if(sila_zvuk >= 700)
                    {
                        sila_zvuk = 700;
                    }
                    if (volume < 0.0f) 
                    {
                        volume = 0.0f;
                    }
                    else if (volume > 1.0f) 
                    {
                        volume = 1.0f;
                    }
                    
                    
                }
            }
           DrawCircle(1360, sila_zvuk, 20, GRAY); 
           
           
           
           SetMusicVolume(muzika, volume);
           DrawText(TextFormat("Music volume: %0.1f", volume ) , 190 , 450 , 20 ,WHITE);
           
           
            
            DrawRectangle(1400, 200, 600, 700, GRAY);
            if(enable_pause == true)
            {
                DrawCircle(1700 , 1000 , 60 , GRAY);
                if(pause == false)
                {
                    //DrawTriangle({1670 , 950}, {1670 , 1050} , {1750 , 1000} , RED);
                    DrawRectangle(1670 , 970 , 20, 60 , BLACK);
                    DrawRectangle(1710 , 970 , 20, 60 , BLACK);
                    if(CheckCollisionPointCircle(mishka, {1700 , 1000} , 60))
                        {
                            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                            {
                                pause = true;
                            }
                        }
                }
                else if (pause == true)
                {
                    DrawTriangle({1680 , 970}, {1680 , 1030} , {1730 , 1000} , BLACK);
                    if(CheckCollisionPointCircle(mishka, {1700 , 1000} , 60))
                        {
                            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                            {
                                pause = false;
                            }
                        }
                }
            }
            
            
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
                    get_sound = { 1400, 190 + (i * 20) , 600, 20 };
                    //DrawRectangleRec(get_sound, BLANK);
                    DrawRectangle(1400 , 200 + (i * 20), 600, 20 , BLANK);
                    DrawText(music_files.paths[i], 1400, 200 + (i * 20), 20, WHITE);
                    
                    
                    
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
                            pause = false;
                            enable_pause = true;
                        }
                    }
                }
                
            }
            //SetMusicVolume(muzika , 0.01);
            if (music_is_selected)
            {
                if(pause == false)
                {
                    UpdateMusicStream(muzika);
                }
           
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
            
            /*
            ADDITIONAL FILTERING : 
            %.0f   // 123
            %.1f   // 123.4
            %.2f   // 123.45
            %.3f   // 123.456
            */
            
            DrawText(TextFormat("Playing for: %.1f" , GetMusicTimePlayed(muzika)),190, 350, 20, WHITE );
            DrawText(TextFormat("Full time of the music: %.1f" , GetMusicTimeLength(muzika)),190, 400, 20, WHITE );
            
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
