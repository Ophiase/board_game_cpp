#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

namespace Texture {
    /*
        Linked to resources into ResourcesLoader::initialize.
    */
    enum SourceTexture {
        BackgroundMain,
        BackgroundMainBlur,
        BackgroundMenu2,
        BackgroundMenu,
        BackgroundPanelBot,
        BackgroundPanelLeft,
        BackgroundPanelRight,
        BackgroundPanelTop,

        TileBrick,
        TileDesert,
        TileRock,
        TileSheep,
        TileWheat,
        TileWood
    };
}
namespace Font {
    /*
        Linked to resources into ResourcesLoader::initialize.
    */
    enum SourceFont {
        OpenSansBold,
        OpenSansExtraBold,
        OpenSansRegular,
        OpenSansLight,
        OpenSansSemiBold
    };
}

namespace Shader {
    /*
        Linked to resources into ResourcesLoader::initialize.
    */
    enum SourceShader {
        Test,
        Mask,
        Coord,
    };
}


class ResourcesLoader {
private:
    static std::map<Texture::SourceTexture, std::string> texturePathMap;
    static std::map<Texture::SourceTexture, sf::Texture> textureMap;
    static void initializeTextures();
    static bool loadTextures();

    static std::map<Font::SourceFont, std::string> fontPathMap;
    static std::map<Font::SourceFont, sf::Font> fontMap;
    static void initializeFonts();
    static bool loadFonts();

    static std::map<Shader::SourceShader, std::string> shaderPathMap;
    static std::map<Shader::SourceShader, sf::Shader> shaderMap;
    static void initializeShaders();
    static bool loadShaders();

public:
    static void initialize();
    static bool load();

    static const sf::Texture& getTexture(Texture::SourceTexture texture);
    static const sf::Font& getFont(Font::SourceFont font);
    static sf::Shader *getShader(Shader::SourceShader shader);
};
