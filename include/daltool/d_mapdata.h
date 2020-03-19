#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <memory>

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>


namespace daldata {

    namespace v1 {

        struct Mesh {
            std::vector<float> m_vertices, m_uvCoords, m_normals;
        };

        struct Material {
            std::string m_diffuseMap, m_roughnessMap, m_metallicMap;
            glm::vec2 m_texScale;
            float m_roughness, m_metallic;
        };

        struct RenderUnit {
            Material m_material;
            Mesh m_mesh;
        };

        struct Transform {
            glm::vec3 m_pos;
            glm::quat m_rot;
            float m_scale;
        };

        struct StaticActor {
            std::string m_name;
            Transform m_trans;
        };

        struct ModelEmbedded {
            std::string m_name;
            std::vector<RenderUnit> m_renderUnits;
            std::vector<StaticActor> m_staticActors;
            bool m_detailedCollider, m_hasRotatingActor;
        };

        struct ModelImported {
            std::string m_resID;
            std::vector<StaticActor> m_staticActors;
            bool m_detailedCollider;
        };

        struct WaterPlane {
            glm::vec3 m_pos, m_deepColor;
            float m_width, m_height, m_flowSpeed, m_waveStrength;
            float m_darkestDepth, m_reflectance;
        };

        struct PointLight {
            glm::vec3 m_color, m_pos;
            float m_maxDistance;
        };

        struct MapChunkInfo {
            std::vector<ModelEmbedded> m_embeddedModels;
            std::vector<ModelImported> m_importedModels;
            std::vector<WaterPlane> m_waterPlanes;
            std::vector<PointLight> m_plights;
        };

    }


    namespace v2 {

        class Material {

        public:
            std::string m_albedoMap, m_roughnessMap, m_metallicMap;
            float m_roughness = 0.5f, m_metallic = 1.f;

        };

        class Mesh {

        public:
            virtual ~Mesh(void) = default;

            virtual size_t numVertices(void) const = 0;
            virtual const float* vertices(void) const = 0;  // Size is 3 * numVertices();
            virtual const float* uvcoords(void) const = 0;  // Size is 2 * numVertices();
            virtual const float* normals(void) const = 0;   // Size is 3 * numVertices();

        };

        class MeshRaw : Mesh {

        public:
            std::vector<float> m_vertices, m_uvcoords, m_normals;

        public:
            virtual size_t numVertices(void) const override;
            virtual const float* vertices(void) const override;
            virtual const float* uvcoords(void) const override;
            virtual const float* normals(void) const override;

        private:
            bool checkSizeValidity(void) const;

        };

        class RenderUnit {

        public:
            std::unique_ptr<Mesh> m_mesh;
            Material m_material;

        };

        class RenderUnitStatic {

        public:
            MeshRaw m_mesh;
            Material m_material;

        };

        class Transform {

        public:
            glm::vec3 m_pos;
            glm::quat m_quat;
            float m_scale = 1.f;

        };

        class StaticActor {
            
        public:
            std::string m_name;
            Transform m_trans;

        };

    }

}
