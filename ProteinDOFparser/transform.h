#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "residue_constants.h"

namespace transform{

// input: atoms coordinates, translation vector, rotation matrix
// output: transformed atoms coordinates
residue_constants::coord translation(
    residue_constants::coord atoms, 
    std::vector<double> translation_vector){
    residue_constants::coord transformed_atoms;
    transformed_atoms.x = atoms.x + translation_vector[0];
    transformed_atoms.y = atoms.y + translation_vector[1];
    transformed_atoms.z = atoms.z + translation_vector[2];
    return transformed_atoms;
};


// // 绕 Z 轴旋转 (偏航角 ψ)
// Rz(ψ) = [
//     [ cos ψ, -sin ψ,  0],
//     [ sin ψ,  cos ψ,  0],
//     [    0,      0,  1]
// ]
// 
// // 绕 Y 轴旋转 (俯仰角 θ)
// Ry(θ) = [
//     [ cos θ,  0,  sin θ],
//     [     0,  1,      0],
//     [-sin θ,  0,  cos θ]
// ]
// 
// // 绕 X 轴旋转 (滚转角 φ)
// Rx(φ) = [
//     [1,     0,      0],
//     [0,  cos φ, -sin φ],
//     [0,  sin φ,  cos φ]
// ]
// 
// R = Rz(ψ) * Ry(θ) * Rx(φ)
//
// R = [
//     [cos ψ cos θ,  cos ψ sin θ sin φ - sin ψ cos φ,  cos ψ sin θ cos φ + sin ψ sin φ],
//     [sin ψ cos θ,  sin ψ sin θ sin φ + cos ψ cos φ,  sin ψ sin θ cos φ - cos ψ sin φ],
//     [   -sin θ,               cos θ sin φ,                     cos θ cos φ          ]
// ]


// input: atoms coordinates, rotation matrix, rotation center
// output: transformed atoms coordinates
residue_constants::coord rotation(
    residue_constants::coord atoms, 
    std::vector<std::vector<double>> rotation_matrix, 
    residue_constants::coord rotation_center){
    residue_constants::coord transformed_atoms;
    transformed_atoms.x = rotation_matrix[0][0] * (atoms.x - rotation_center.x) + rotation_matrix[0][1] * (atoms.y - rotation_center.y) + rotation_matrix[0][2] * (atoms.z - rotation_center.z) + rotation_center.x;
    transformed_atoms.y = rotation_matrix[1][0] * (atoms.x - rotation_center.x) + rotation_matrix[1][1] * (atoms.y - rotation_center.y) + rotation_matrix[1][2] * (atoms.z - rotation_center.z) + rotation_center.y;
    transformed_atoms.z = rotation_matrix[2][0] * (atoms.x - rotation_center.x) + rotation_matrix[2][1] * (atoms.y - rotation_center.y) + rotation_matrix[2][2] * (atoms.z - rotation_center.z) + rotation_center.z;
    
    transformed_atoms.x += rotation_center.x;
    transformed_atoms.y += rotation_center.y;
    transformed_atoms.z += rotation_center.z;
    return transformed_atoms;
};

// input: euler angles(α, β, γ or ψ, θ, φ), rotation center
// output: rotation matrix
std::vector<std::vector<double>> euler_to_rotation_matrix(std::vector<double> euler_angles){
    double alpha = euler_angles[0];
    double beta = euler_angles[1];
    double gamma = euler_angles[2];
    std::vector<std::vector<double>> rotation_matrix;
    rotation_matrix[0][0] = cos(alpha) * cos(beta);
    rotation_matrix[0][1] = cos(alpha) * sin(beta) * sin(gamma) - sin(alpha) * cos(gamma);
    rotation_matrix[0][2] = cos(alpha) * sin(beta) * cos(gamma) + sin(alpha) * sin(gamma);
    rotation_matrix[1][0] = sin(alpha) * cos(beta);
    rotation_matrix[1][1] = sin(alpha) * sin(beta) * sin(gamma) + cos(alpha) * cos(gamma);
    rotation_matrix[1][2] = sin(alpha) * sin(beta) * cos(gamma) - cos(alpha) * sin(gamma);
    rotation_matrix[2][0] = -sin(beta);
    rotation_matrix[2][1] = cos(beta) * sin(gamma);
    rotation_matrix[2][2] = cos(beta) * cos(gamma);
    return rotation_matrix;
};

} // namespace transform

#endif // TRANSFORM_H
