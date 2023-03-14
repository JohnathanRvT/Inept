cbuffer ConstantBuffer : register(b0)
{
    matrix World;
    matrix View;
    matrix Projection;
};

struct VS_INPUT
{
    float4 position : POSITION;
    float4 color : COLOR;
};

struct PS_INPUT
{
    float4 position : SV_POSITION;
    float4 color : COLOR;
};

PS_INPUT main(VS_INPUT input)
{
    PS_INPUT output = (PS_INPUT)0;
    output.position = mul(input.position, World);
    output.position = mul(output.position, View);
    output.position = mul(output.position, Projection);
    output.color = input.color;
    return output;
}
